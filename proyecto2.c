/* Este programa quiere que con dos puntos ingresados por el usuario y asi encontrar la ecuación de la recta.
 Autores:Leidy Ximena Garzón y Sebastian Babativa Veloza
 Versión:1.0
 */

 #include <stdio.h>

  

typedef  struct punto{
	 float x,y;
	 
     }punto;//estructa que contiene los puntos x y y
 void menu(int *opc);
 void insertar_puntos( punto *p1,punto *p2,int *ing_puntos,float *pend,float *intercepto_y);
 void Mostrar_pendiente(punto p1,punto p2,float pend);
 void Mostrar_cruce_y(punto p1, punto p2,float intercepto_y);
 void Mostrar_ecuacion(punto p1,punto p2,float pend,float intercepto_y);	 

 void main(void)
 {
	 
	 
	 int opcion=0,ingreso_dat=0;//ingreso_dat bandera para saber si el usuario si ingreso los puntos
     punto punto1,punto2;
	 float pendiente=0,cruce_y=0;
	 
	
	printf(" \n Buen dia \n \n Este programa realiza distintas operaciones con dos puntos \n");//saludo 
	
	
	do{
	
	menu(&opcion);
	
	
		switch(opcion)
		{
		case 1:
		insertar_puntos(&punto1,&punto2,&ingreso_dat,&pendiente,&cruce_y); 
		break;
		case 2: 
		if(ingreso_dat==1)// volver a pedir los puntos si no los ingreso
	    { 
		Mostrar_pendiente(punto1,punto2,pendiente);//mostrar la pendiente 
		}
		else
		{
		printf("\n\nPrimero debe ingresar los puntos\n\n");
		} 
		break;
		case 3:
		if(ingreso_dat==1)// volver a pedir los puntos si no los ingreso
	    { 
        Mostrar_cruce_y(punto1,punto2,cruce_y);
		}
		else
	    {
		printf("\n\nPrimero debe ingresar los puntos\n\n");
		} 
		 break;
        case 4:
		if(ingreso_dat==1)// volver a pedir los puntos si no los ingreso
	    { 
        Mostrar_ecuacion(punto1,punto2,pendiente,cruce_y);
		}
		else
	    {
		printf("\n\nPrimero debe ingresar los puntos\n\n");
		} 
		break;
        case 5: 	
	    printf("\n\nGracias por utilizar el programa,vuelva pronto\n\n");
	    break;
		default:
		printf("\n\nOpción incorrecta\n\n");
		break;
        }
	}while(opcion!=5);
 }
 
 void menu(int *opc)
 {	
	 printf("\n\t Menú\n");
	 printf("\n\n Inserta el número donde deseas ingresar\n\n");
	 printf("\n\n 1.Ingresar puntos\n");
	 printf("\n 2.Mostrar pendiente\n");
	 printf("\n 3.Mostrar Cruce con el eje Y\n");
	 printf("\n 4.Mostrar ecuación completa\n");
	 printf("\n 5.Salir\n\n");
	 scanf("%d",opc);
 }
 
 void insertar_puntos( punto *p1,punto *p2,int *ing_puntos,float *pend,float *intercepto_y)//insertar los puntos y realizar las operaciones 
 
 {
	 int error=0;
	 do
	 {
	 printf("\n\nLa forma de ingresar los puntos es primero x1 y luego y1 para que el punto quede de la siguiente manera(x1,y1)\n\n");
     printf("\n\n Ingrese la primera componente del primer punto x1:\n");
     scanf("%f",&p1->x);
     printf("\n\n Ingrese la segunda componente del primer punto y1:\n");
	 scanf("%f",&p1->y);
     printf("\n\nAhora el segundo punto que es de la misma forma que el anterior  primero x2 y luego y2 para que quede(x2,y2)\n\n");
	 printf("\n\n Ingrese la primera componente del primer punto x2:\n");
	 scanf("%f",&(p2)->x);
	 printf("\n\n Ingrese la segunda componente del primer punto y2:\n");
	 scanf("%f",&(p2)->y);
	 *ing_puntos=1;
	 
		if((p2->x)-(p1->x)==0)
		{
		printf("\n los numeros insertados en x1 y x2 son iguales por lo tanto se esta generando \n una indeterminacion porfavor insterte nuevamente un numero valido");
		error=1;
		} 
		else
		{
		error=0;		 
		}
		} while (error!=0);// pedir los números hasta que los ingrese correctamente 
		
		*pend=(p2->y-p1->y)/(p2->x-p1->x);
		*intercepto_y=(p1->y)-(*pend)*(p1->x);
		//mostrar los números ingresados
		
		printf("los numeros ingresados son p1(%.3f,%.3f) y P2(%.3f,%.3f)",p1->x,p1->y,p2->x,p2->y);
		

 }

void Mostrar_pendiente(punto p1,punto p2,float pend)//mostrar la pendiente
{ 

		
		printf("\n\nLa pendiente que forman estos dos puntos es:%.3f\n\n",pend);
}
 void Mostrar_cruce_y(punto p1,punto p2,float intercepto_y)// mostrar el cruce con el eje y 
 {
		
		printf("\n\n El cruce con el eje y de los dos puntos es:%.3f\n\n",intercepto_y);
	 
 }	 
 
  void Mostrar_ecuacion(punto p1,punto p2,float pend,float intercepto_y)// mostrar los puntos y la ecuacion resultante 
 {
	
	printf("\n\n La ecuación de la recta que forman los dos puntos p1(%.3f,%.3f) y P2(%.3f,%.3f)\n es: y= %.3fx+ %.3f\n\n",p1.x,p1.y,p2.x,p2.y,pend,intercepto_y);
      
 }