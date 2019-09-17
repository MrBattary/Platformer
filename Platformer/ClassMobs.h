
#include <SFML/Graphics.hpp>

using namespace sf;

class Mobs
{
public:
	float xM;							//Положение виртуальной модели по х
	float yM;							//Положение виртуальной модели по y
	float wM;							//Ширина модели
	float hM;							//Высота модели
	float dxM;							//Ускорение по х
	float dyM;							//Ускорение по у
	float xMReal;						//Х реальной модели внутри виртуальной модели относительной всей оси
	float yMReal;						//Y реальной модели внутри виртуальной модели относительной всей оси
	float xMRealInside;					//Х реальной модели внутри виртуальной модели
	float yMRealInside;					//Y реальной модели внутри виртуальной модели
	float wMReal;						//Ширина реальной модели внутри виртуальной модели
	float hMReal;						//Высота реальной модели внутри виртуальной модели
	float speedMX;						//Скорость персонажа по X
	float speedMY = 0;					//Скорость персонажа по Y
	int dirM;							//Направление движения	Данная "роза направлений" будет использоваться часто,советую её запомнить.
	float moveTimer = 0;
	float tpstop = 0;
	int sws = 0;
	String File;						//Файл с расширением
	Image image;						//Изображение
	Texture texture;					//Текстура
	Sprite sprite;						//Спрайт
	String name;
	bool battleMode = false;			//Боевая стойка
	bool battleModeAvaible = false;		//Проверка на боевую стойку
	bool moveLeft = true;				//Нужна для проверки на стандартное движение влево
	bool moveOnlyLeft = true;			//Проверка на лево и прямо
	bool moveRight = true;				//Нужна для проверки на стандартное движение вправо
	bool moveOnlyRight = true;			//Проверка на право и прямо
	bool buttonIsPressed = false;		//Нажата ли клавиша нужно для idle
	bool previousDirectionMove = false; //Предыдущее направление движения false-вправо true-влево
	bool gotov = false;
	bool onlyOneAnimation = true;		//Воспроизведение только одной анимации по всем направлениям
	bool onlyOneAnimationOneDir = true;	//Воспроизведение только одной анимации в одном направлении
	int chet=1;
	float currentFrame = 0;				//Номер текущего кадра циклической анимации
	float currentUncycleFrame = 0;		//Номер текущего кадра не циклической анимации
	bool passable;
	bool Left = false;
	bool right = true;
	bool stop = false;
	bool lifeM;
	int healthM;						//Здоровье Героя 0-100

	FloatRect rectM;

	Mobs(String F,String Name, float X, float Y, float W, float H, float XReal, float YReal, float WReal, float HReal, int Health)		//Конструктор 
	{
		File = F;
		wM = W;
		hM = H;
		name = Name;
		image.loadFromFile("Sprites/" + File);				//Загружаем в него файл
		image.createMaskFromColor(Color(255, 255, 255));	//Прозрачность
		texture.loadFromImage(image);						//Текстура
		sprite.setTexture(texture);							//Спрайт
		xM = X-500;												//Координаты
		yM = Y;
		xMRealInside = XReal;
		yMRealInside = YReal;
		xMReal = xM +xMRealInside;
		yMReal = yM +yMRealInside;
		wMReal = WReal;
		hMReal = HReal;
		healthM = Health;									//Здоровье
		passable = false;
		sprite.setTextureRect(IntRect(1, 1, wM, hM));		//Вырезаем персонажа
		speedMX = 0.10; 
		srand(time(NULL));
		sws = 1 + rand() % 3;
		
	}
	
	//Функции-CHANGE помощники, могут изменять значения
	void update(float time)
	{

		int sWs = Get_SWS();
		FloatRect a(xMReal - 25, yMReal - 25, 52, 75);
		rectM = a;
		if (lifeM) {
			if (right) { sprite.setPosition(xMReal, yMReal); MobsRespawn(time); }

			switch (sWs)
			{
			case 1:
				if (!right) {
					moveTimer += time;
					if (moveTimer >= 3000) {
						chet += 1;
						if (chet == 5)
						{
							chet = 1;
						}
						moveTimer = 0;
						Left = false;
					}
					if (chet != 2 && chet != 4)
						xMReal += speedMX * time;

					FloatRect a(xMReal - 25, yMReal - 25, 52, 75);
					rectM = a;
					sprite.setPosition(xMReal, yMReal);

					if (healthM > 0) {
						switch (chet)
						{
						case 1:
							MobsMoveLeft(time);

							if (!Left) {
								Left = true;
								speedMX *= -1;
							}
							break;
						case 2:
							MobsIdleLeft(time);
							break;
						case 3:
							MobsMoveRight(time);

							if (!Left) {
								Left = true;
								speedMX *= -1;
							}
							break;
						case 4:
							MobsIdleRight(time);
							break;
						default:
							break;
						}

					}
				}
				break;
			case 2:
				speedMX = 0;

				sprite.setPosition(xMReal, yMReal);
				MobsIdleRight(time);
				break;
			case 3:
				speedMX = 0;

				sprite.setPosition(xMReal, yMReal);
				MobsIdleLeft(time);
				break;
			}
		}
		if (healthM <= 0) {
			lifeM = false;
			if (!stop) {
				if (chet == 3 || chet == 4)
				{
					MobsDieRight(time);
				}
				else if (chet == 1 || chet == 2)
				{
					MobsDieLeft(time);

				}
			}
		}



	}

	
	//Функции-GET помощники
	Sprite Get_Sprite() { return sprite; }										//Получить Спрайт

	FloatRect getRect() {													   //Получить прямоуг-ик
		return rectM;
	}
	int MobsKick(float);
	int MobsDieLeft(float);
	float Get_XM() { return xM; }
	//Получить положение виртуальной модели по х
	float Get_YM() { return yM; }
	int Get_SWS() { return sws; }//Получить положение виртуальной модели по у
	float Get_WM() { return wM; }												//Получить ширину модели
	float Get_HM() { return hM; }												//Получить высоту модели
	float Get_XMReal() { return xMReal; }										//Получить положение реальной модели по х
	float Get_YMReal() { return yMReal; }										//Получить положение реальной модели по у
	float Get_WMReal() { return wMReal; }										//Получить ширину реальной модели
	float Get_HMReal() { return hMReal; }										//Получить высоту реальной модели
	float Get_speedMX() { return speedMX; }										//Получить speedHX
	float Get_speedMY() { return speedMY; }										//Получить speedHY									//Получить comboH
	bool Get_moveLeft() { return moveLeft; }									//Можно ли двигаться влево
	bool Get_moveOnlyLeft() { return moveOnlyLeft; }							//Можно ли двигаться только прямо влево
	bool Get_moveRight() { return moveRight; }									//Можно ли двигаться вправо
	bool Get_moveOnlyRight() { return moveOnlyRight; }							//Можно ли двигаться только прямо вправо
	bool Get_buttonIsPressed() { return buttonIsPressed; }						//Нажата ли кнопка
	bool Get_previousDirectionMove() { return previousDirectionMove; }			//Узнать предыдущее направление false-вправо true-влево
	bool Get_passable() { return passable; };
	bool Get_onlyOneAnimation() { return onlyOneAnimation; }					//Возможно ли воспроизведение только одной анимации
	bool Get_onlyOneAnimationOneDir() { return onlyOneAnimationOneDir; }		//Возможно ли воспроизведение только одной анимации в одном направлении
	bool Get_battleMode() { return battleMode; }								//Какая стойка
	bool Get_battleModeAvaible() { return battleModeAvaible; }					//Возможно ли переключение в другую стойку

	//Функции-SET помощники
	void Set_XM(float value) { xM = value; }									//Установить положение виртуальной модели по х
	void Set_YM(float value) { yM = value; }									//Установить положение виртуальной модели по у
	void Set_XMReal(float value) { xMReal = value; }							//Установить положение реальной модели по х
	void Set_YMReal(float value) { yMReal = value; }							//Установить положение реальной модели по у
	void Set_WMReal(float value) { wMReal = value; }							//Установить ширину реaльной модели
	void Set_HMReal(float value) { hMReal = value; }							//Установить высоту реaльной модели
	void Set_moveLeft(bool value) { moveLeft = value; }							//Установить движение влево
	void Set_moveOnlyLeft(bool value) { moveOnlyLeft = value; }					//Установить движение только прямо влево
	void Set_moveRight(bool value) { moveRight = value; }							//Установить движение вправо
	void Set_moveOnlyRight(bool value) { moveOnlyRight = value; }					//Установить движение только прямо вправо
	void Set_buttonIsPressed(bool value) { buttonIsPressed = value; }				//Установить нажатие клавиши
	void Set_previousDirectionMove(bool value) { previousDirectionMove = value; }	//Установить предыдущее направление движения

	void Set_onlyOneAnimation(bool value) { onlyOneAnimation = value; }			//Установить воспроизведение только одной анимации
	void Set_onlyOneAnimationOneDir(bool value) { onlyOneAnimationOneDir = value; }//Установить воспроизведение только одной анимации в одном направлении
	void Set_battleMode(bool value) { battleMode = value; }						//Установить стойку
	void Set_battleModeAvaible(bool value) { battleModeAvaible = value; }		//Установить возможность смены стойки


	void DrawM(float);															//Отрисовка персонажа, связь физики и анимации
	void SetRealSize(float, float, float, float);								//Изменение размеров внутренней модели

	/*
	Функции отвечающие за связь анимации и её физической составляющей
	*/
	//Движение вверх-вниз 
	int AnimationLife(float);
	int MobsMoveTop(float, bool, bool, bool);
	int MobsMoveDown(float, bool, bool, bool);
	int MobsRespawn(float);
	//AFK	
	int MobsIdleLeft(float);
	int MobsIdleRight(float);
	int MobsIdleCrouchLeft(float);
	int MobsIdleCrouchRight(float);
	int MobsDieRight(float);

	//Движение вправо	
	int MobsMoveRight(float);
	int MobsMoveRightFast(float);
	int MobsMoveRightSlow(float);
	int MobsMoveRightCrouch(float);
	int MobsMoveRightUp(float);
	int MobsMoveRightFastUp(float);
	int MobsMoveRightSlowUp(float);
	int MobsMoveRightCrouchUp(float);
	int MobsMoveRightDown(float);
	int MobsMoveRightFastDown(float);
	int MobsMoveRightSlowDown(float);
	int MobsMoveRightCrouchDown(float);

	//Движение влево	
	int MobsMoveLeft(float);
	int MobsMoveLeftFast(float);
	int MobsMoveLeftSlow(float);
	int MobsMoveLeftCrouch(float);
	int MobsMoveLeftUp(float);
	int MobsMoveLeftFastUp(float);
	int MobsMoveLeftSlowUp(float);
	int MobsMoveLeftCrouchUp(float);
	int MobsMoveLeftDown(float);
	int MobsMoveLeftFastDown(float);
	int MobsMoveLeftSlowDown(float);
	int MobsMoveLeftCrouchDown(float);

	//Боевка
	int MobsChangeModToBattleLeft(float);
	int MobsChangeModToCivilLeft(float);
	int MobsChangeModToBattleRight(float);
	int MobsChangeModToCivilRight(float);
	int LightBlowRight1(float);
	int HeavyBlowRight2(float);
	int LightBlowLeft3(float);
	int HeavyBlowLeft4(float);


	//Через эту функцию происходит получение урона героем
	void MobsGetDamage(float a);


	//~Hero() {}; Деструктор пока в комментах ибо нефиг
};
class Mobsv1 :public Mobs {
public:
	
	Mobsv1(String F, String Name, float X, float Y, float W, float H, float XReal, float YReal, float WReal, float HReal, int Health) :Mobs(F,Name, X, Y, W, H, XReal, YReal, WReal, HReal, Health) {

		if (name == "Number1") {
			sprite.setTextureRect(IntRect(0, 0, W, H));
		}
	}

};
class Mobsv2 :public Mobs {
public:

	Mobsv2(String F, String Name, float X, float Y, float W, float H, float XReal, float YReal, float WReal, float HReal, int Health) :Mobs(F, Name, X, Y, W, H, XReal, YReal, WReal, HReal, Health) {

		if (name == "Number2") {
			sprite.setTextureRect(IntRect(0, 0, W, H));
		}
	}

};





