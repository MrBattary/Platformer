#pragma once
/*
Тут описываем Героя, Его положение по х/y, анимации итд
Только объявление! Исключение: Функции-Помощники
*/

#include <SFML/Graphics.hpp>

using namespace sf;

class Hero
{
protected:
	float xH;							//Положение виртуальной модели по х
	float yH;							//Положение виртуальной модели по y
	float wH;							//Высота модели
	float hH;							//Ширина модели
	float dxH;							//Ускорение по х
	float dyH;							//Ускорение по у
	float speedHX=0;					//Скорость персонажа по X
	float speedHY=0;					//Скорость персонажа по Y
	int dirH;							//Направление движения	Данная "роза направлений" будет использоваться часто,советую её запомнить.

											//7 4 8
											// ↖↑↗
											//3←0→1
											// ↙↓↘
											//6 2 5

	int healthH;						//Здоровье Героя 0-100

	String File;						//Файл с расширением
	Image image;						//Изображение
	Texture texture;					//Текстура
	Sprite sprite;						//Спрайт

	bool moveLeft = true;				//Нужна для проверки на стандартное движение влево
	bool moveOnlyLeft = true;			//Проверка на лево и прямо
	bool moveRight = true;				//Нужна для проверки на стандартное движение вправо
	bool moveOnlyRight = true;			//Проверка на право и прямо
	bool buttonIsPressed = false;		//Нажата ли клавиша нужно для idle
	bool previousDirectionMove = false; //Предыдущее направление движения false-вправо true-влево
	bool crouchAviable = true;			//Можно ли присесть,исключает возможность воспроизведения анимации HeroCrouchIdle в движении 
	bool slideAviable = false;			//Скользим?
	bool jumpAviable = false;			//Прыгаем?
	bool jumpLargeAviable = false;		//Далеко прыгаем?
	bool controlAviable = true;			//Контроль управления с клавиатуры
	bool onlyOneAnimation = true;		//Воспроизведение только одной анимации по всем направлениям
	bool onlyOneAnimationOneDir = true;	//Воспроизведение только одной анимации в одном направлении

	float currentFrame = 0;				//Номер текущего кадра циклической анимации
	float currentUncycleFrame = 0;		//Номер текущего кадра не циклической анимации

	float cooldownAnimationJump = 0;	//Кулдаун на анимацию прыжков
	float cooldownAnimationSlide = 0;	//Кулдаун на анимацию скольжения
public:
	Hero(String F, float X, float Y, float W, float H)		//Конструктор 
	{
		File = F;
		wH = W;
		hH = H;
		image.loadFromFile("Sprites/"+File);				//Загружаем в него файл
		image.createMaskFromColor(Color(255, 255, 255));	//Прозрачность
		texture.loadFromImage(image);						//Текстура
		sprite.setTexture(texture);							//Спрайт
		xH = X;
		yH = Y;
		sprite.setTextureRect(IntRect(0, 0, wH, hH));		//Вырезаем персонажа
	}
	//Функции-CHANGE помощники могут изменять значения
	void Change_speedHX(float value) { speedHX += value; }
	void Change_speedHY(float value) { speedHY += value; }
	void Change_cooldownAnimationJump(float value) { cooldownAnimationJump += value; }
	void Change_cooldownAnimationSlide(float value) { cooldownAnimationSlide += value; }

	//Функции-GET помощники
	Sprite Get_Sprite() { return sprite; }										//Получить Спрайт
	float Get_speedXH() { return speedHX; }										//speedHX
	float Get_speedXY() { return speedHY; }										//speedHY
	float Get_cooldownAnimationJump() { return cooldownAnimationJump; }			//cooldownAnimationJump
	float Get_cooldownAnimationSlide() { return cooldownAnimationSlide; }		//cooldownAnimationSlide
	bool Get_moveLeft() { return moveLeft; }									//Можно ли двигаться влево
	bool Get_moveOnlyLeft() { return moveOnlyLeft; }							//Можно ли двигаться только влево
	bool Get_moveRight() { return moveRight; }									//Можно ли двигаться вправо
	bool Get_moveOnlyRight() { return moveOnlyRight; }							//Можно ли двигаться только вправо
	bool Get_buttonIsPressed() { return buttonIsPressed; }						//Нажата ли кнопка
	bool Get_previousDirectionMove() { return previousDirectionMove; }			//Узнать предыдущее направление false-вправо true-влево
	bool Get_crouchAviable() { return crouchAviable; }							//Можно ли присесть true-да, false-нет
	bool Get_slideAviable() { return slideAviable; }							//Доступно ли скольжение
	bool Get_jumpAviable() { return jumpAviable; }								//Доступен ли прыжок
	bool Get_jumpLargeAviable() { return jumpLargeAviable; }					//Доступен ли мощный прыжок
	bool Get_controlAviable() { return controlAviable; }						//Доступно ли управление с клавиатуры
	bool Get_onlyOneAnimation() { return onlyOneAnimation; }					//Возможно ли воспроизведение только одной анимации
	bool Get_onlyOneAnimationOneDir() { return onlyOneAnimationOneDir; }		//Возможно ли воспроизведение только одной анимации в одном направлении


	//Функции-SET помощники
	void Set_moveLeft(bool value) { moveLeft=value; }							//Установить движение влево
	void Set_moveOnlyLeft(bool value) { moveOnlyLeft=value; }					//Установить движение только влево
	void Set_moveRight(bool value) { moveRight=value; }							//Установить движение вправо
	void Set_moveOnlyRight(bool value) { moveOnlyRight=value; }					//Установить движение только вправо
	void Set_buttonIsPressed(bool value) { buttonIsPressed=value; }				//Установить нажатие клавиши
	void Set_previousDirectionMove(bool value) { previousDirectionMove=value; }	//Установить предыдущее направление движения
	void Set_crouchAviable(bool value) { crouchAviable=value; }					//Установить возможность приседать
	void Set_slideAviable(bool value) { slideAviable=value; }					//Установить возможность скользить
	void Set_jumpAviable(bool value) { jumpAviable=value; }						//Установить возможность прыжка
	void Set_jumpLargeAviable(bool value) { jumpLargeAviable=value; }			//Установить возможность мощного прыжка
	void Set_controlAviable(bool value) { controlAviable=value; }				//Установить возможность управления персонажем с клавиатуры
	void Set_onlyOneAnimation(bool value) { onlyOneAnimation = value; }			//Установить воспроизведение только одной анимации
	void Set_onlyOneAnimationOneDir(bool value){onlyOneAnimationOneDir = value;}//Установить воспроизведение только одной анимации в одном направлении


	void Draw(float);															//Отрисовка персонажа, связь физики и анимации

	/*
	Функции отвечающие за связь анимации и её физической составляющей
	*/
	//Движение вверх-вниз 
	int HeroMoveTop(float,bool,bool,bool);
	int HeroMoveDown(float,bool,bool,bool);

	//AFK	
	int HeroIdleLeft(float);
	int HeroIdleRight(float);
	int HeroIdleCrouchLeft(float);
	int HeroIdleCrouchRight(float);

	//Скольжение	
	void HeroSlideChoise(float);
	int HeroSlideRight(float);
	int HeroSlideRightUp(float);
	int HeroSlideRightDown(float);
	int HeroSlideLeft(float);
	int HeroSlideLeftUp(float);
	int HeroSlideLeftDown(float);

	//Выбор прыжка
	void HeroJumpChoise(float);
	void HeroJumpLargeChoise(float);

	//Малые прыжки	
	int HeroJumpRight(float);
	int HeroJumpRightUp(float);
	int HeroJumpRightDown(float);
	int HeroJumpLeft(float);
	int HeroJumpLeftUp(float);
	int HeroJumpLeftDown(float);

	//Большие прыжки	
	int HeroJumpLargeRight(float);	
	int HeroJumpLargeRightUp(float);
	int HeroJumpLargeRightDown(float);
	int HeroJumpLargeLeft(float);
	int HeroJumpLargeLeftUp(float);
	int HeroJumpLargeLeftDown(float);

	//Движение вправо	
	int HeroMoveRight(float);
	int HeroMoveRightFast(float);
	int HeroMoveRightSlow(float);
	int HeroMoveRightCrouch(float);
	int HeroMoveRightUp(float);
	int HeroMoveRightFastUp(float);
	int HeroMoveRightSlowUp(float);
	int HeroMoveRightCrouchUp(float);
	int HeroMoveRightDown(float);
	int HeroMoveRightFastDown(float);
	int HeroMoveRightSlowDown(float);
	int HeroMoveRightCrouchDown(float);

	//Движение влево	
	int HeroMoveLeft(float);
	int HeroMoveLeftFast(float);
	int HeroMoveLeftSlow(float);
	int HeroMoveLeftCrouch(float);
	int HeroMoveLeftUp(float);
	int HeroMoveLeftFastUp(float);
	int HeroMoveLeftSlowUp(float);
	int HeroMoveLeftCrouchUp(float);
	int HeroMoveLeftDown(float);
	int HeroMoveLeftFastDown(float);
	int HeroMoveLeftSlowDown(float);
	int HeroMoveLeftCrouchDown(float);
	

	//Через эту функцию происходит получение урона героем
	void HeroGetDamage();
	
	//Диалоги героя
	void HeroDialogs();


	//~Hero() {}; Деструктор пока в комментах ибо нефиг
};


inline void Hero::HeroDialogs()
{
}