/*Создать структуру Car, с полями model, fuel и location. Машина приходит с завода с пустым баком, ее нужно заправить ( функция refill). Машина может ехать (функция move), если есть бензин и не ехать, если бензина нет. Во время езды бензин ощутимо расходуется.

Создать несколько машин. Присвоить им название моделей и первичную точку координат. Заправить и отправить их в путь. Если машины окажутся в одной и той же точке, значит случилось ДТП. ДТП случилось.

Если вывести в консоль структуру Car, должно отобразиться: модель, количество бензина и текущая позиция.*/

#include <stdio.h>
typedef struct {
   int x;
   int y; 
    
} Point;

typedef struct {
  char model[10];
  int fuel;
  Point location;  
    
} Car;

void printCar(Car *car) {
    printf("Model of this car is - %s\n", car->model);
    printf("Quantity of fuel is %d\n", car->fuel);
    printf("Car`s present position is (%d,%d) \n",car->location.x,car->location.y );
}

void initCar(Car *car) {
    printf("Enter model and current position of car: ");
    scanf("%s", car->model);
    scanf("%d %d", &(car->location.x), &(car->location.y));
    car->fuel = 0;
    }

void refill(Car *car) {
    car->fuel = 100;
}

void move(Car *car) {
    if ( car->fuel == 0 ) {
        printf("There is no fuel in this car,please refill.\n");
    } else {
        printf("How far(in km) do you want to move?\n");
        int path;
        scanf("%d", &path);
        car->fuel -= path*20;
        car->location.x += path;         
    }
}

void carAccident (Car *car1, Car *car2) {
    if ( car1->location.x == car2->location.x ) {
        printf("Danger! It`s an accident between %s and %s\n", car1->model, car2->model);
    } else {
        printf("There is no accident between %s and %s\n", car1->model, car2->model);
    }
}
int main() {
    Car Toyota, Nissan, Lamborgini;
    
    initCar(&Toyota);
    initCar(&Nissan);
    initCar(&Lamborgini);
    
    printf("\n");
    
    refill(&Toyota);
    refill(&Nissan);
    refill(&Lamborgini);
    
    printf("\n");
    
    move(&Toyota);
    move(&Nissan);
    move(&Lamborgini);
   
   printf("\n");
    
    carAccident(&Toyota, &Nissan);
    carAccident(&Toyota, &Lamborgini);
    carAccident(&Lamborgini, &Nissan);
    
    printf("\n");
    
    printCar(&Toyota);
    printCar(&Nissan);
    printCar(&Lamborgini);
      
    return 0;
}
