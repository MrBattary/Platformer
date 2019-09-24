
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
	
	bool moveLeft = true;				//Нужна для проверки на стандартное движение влево
	bool moveRight = true;				//Нужна для проверки на стандартное движение вправо
	bool buttonIsPressed = false;		//Нажата ли клавиша нужно для idle
	bool gotov = false;
	bool onlyOneAnimation = true;		//Воспроизведение только одной анимации по всем направлениям
	bool onlyOneAnimationOneDir = true;	//Воспроизведение только одной анимации в одном направлении
	int chet=1;
	float currentFrame = 0;				//Номер текущего кадра циклической анимации
	float currentUncycleFrame = 0;		//Номер текущего кадра не циклической анимации
	bool passable;
	bool Left = false;					//Двмижняк влеко
	bool right = true;					//Движняк вправо
	bool stop = false;					//Стоим
	bool lifeM;							//Жизнь моба
	int healthM;						//Здоровье Моба
	FloatRect rectM;

	Mobs( float X, float Y, float W, float H, float XReal, float YReal, float WReal, float HReal, int Health)		//Конструктор 
	{
		File = "HeavyBandit_Spritesheet.png";
		wM = W;
		hM = H;
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
	int Get_SWS() { return sws; }												// Получаем то что делает МОБ
	float Get_XMReal() { return xMReal; }										//Получить положение реальной модели по х
	float Get_YMReal() { return yMReal; }										//Получить положение реальной модели по у
	float Get_WMReal() { return wMReal; }										//Получить ширину реальной модели
	float Get_HMReal() { return hMReal; }										//Получить высоту реальной модели
	float Get_speedMX() { return speedMX; }										//Получить speedHX
	float Get_speedMY() { return speedMY; }										//Получить speedHY									//Получить comboH
	bool Get_passable() { return passable; };
	void DrawM(float);															//Отрисовка персонажа, связь физики и анимации
	void SetRealSize(float, float, float, float);								//Изменение размеров внутренней модели

	/*
	Функции отвечающие за связь анимации и её физической составляющей
	*/
	//Движение Респавн
	int MobsRespawn(float);
	//AFK	
	int MobsIdleLeft(float);
	int MobsIdleRight(float);
	int MobsDieRight(float);

	//Движение вправо	
	int MobsMoveRight(float);

	//Движение влево	
	int MobsMoveLeft(float);

	//Боевка

	//Через эту функцию происходит получение урона Мобом
	void MobsGetDamage(float a);


	//~Hero() {}; Деструктор пока в комментах ибо нефиг
};
class Mobsv1 :public Mobs {
public:
	
	Mobsv1( float X, float Y, float W, float H, float XReal, float YReal, float WReal, float HReal, int Health) :Mobs (X, Y, W, H, XReal, YReal, WReal, HReal, Health) {

		
			sprite.setTextureRect(IntRect(0, 0, W, H));
		
	}
	

};
class Mobsv2 :public Mobs {
public:

	Mobsv2( float X, float Y, float W, float H, float XReal, float YReal, float WReal, float HReal, int Health) :Mobs( X, Y, W, H, XReal, YReal, WReal, HReal, Health) {

		
			sprite.setTextureRect(IntRect(0, 0, W, H));
		
	}


};





