#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void main() {
	setlocale(LC_CTYPE, "Spanish");      			//Para que acepte acentos y así
	srand(time(NULL));
	char reintentar, elec;
	
	do {
		char continuar;
		
		printf("\n¿Que juegos quieres jugar? Escribe 1 para 'Piedra, papel o tijera' o 2 para 'Adivina el número': ");			 			//Generar numero random entre 1 y 200
		scanf("%d", &elec);
		
		if (elec==1) {
			int jugador, oponente;
	    	char *opciones[] = {"Piedra", "Papel", "Tijera"};
	
		    // Inicializar generar numeros aleatorios
		
		    do {
		        printf("\nHas elegido el juego de Piedra,Papel o Tijera, pulsa cualquier tecla para continuar. \n");
		        getch();
		        printf("\nEsta son las opciones:\n");
		        printf("1. Piedra\n");
		        printf("2. Papel\n");
		        printf("3. Tijera\n");
		        printf("\nElige tu opción (1-3): ");
		        scanf("%d", &jugador);
		
		        // Validar entrada del jugador
		        if (jugador < 1 || jugador > 3) {
		            printf("Esto no es valido. Intentalo de nuevo.\n");
		            continue;
		        }
		
		        oponente = rand() % 3 + 1;  // Números entre 1 y 3
		
		        printf("\nHas elegido: %s\n", opciones[jugador - 1]);
		        printf("El oponente ha eligido: %s\n", opciones[oponente - 1]);
		
		        // Decir quien es el ganador
		        if (jugador == oponente) {
		            printf("Has Empatado\n");
		        } else if ((jugador == 1 && oponente == 3) || (jugador == 2 && oponente == 1) || (jugador == 3 && oponente == 2)) {
		            printf("Has Ganado\n");
		        } else {
		            printf("Has Perdido :(\n");
		        }
		
		        // Preguntar si quiere volver a intentarlo
		        printf("\n¿Quieres volver a intentarlo? (s/n): ");
		        fflush(stdin);
		        scanf("%c", &continuar);
		
		    } while (continuar == 's' || continuar == 'S');
			printf("\nGracias por jugar a nuestro juego para el reto.\n");
		    
		    printf("\nQuieres volver al selector de juegos? (s/n): ");
		    fflush(stdin);
			scanf("%c", &reintentar);
		
		} else if (elec==2) {
			
			char continuar2;
			
			do {
				int n, r, cont, dif, lim;			 			//Definir variables	
				lim = 200; cont = 1;							//Variable lim para el limite del numero random; inicializar contador
				r = (rand() % lim) + 1;
				
				do {
					printf("\nHas elegido el juego de adivina el número, pulsa cualquier tecla para continuar. "); 							
					getch();
					printf("\nIntroduce el número: ");																					//Preguntar y leer el numero
					scanf("%d", &n);
					
					if (n<1 || n>200) {											//Comprobar que el núm esta dentro de los valores válidos
						printf("Introduce un válor válido.");
					} else if (n != r) {										//Comprobar si los numeros son diferentes
						if (n > r) {											//Comprobar cual es mayor, para que la diferencia no sea negativa
							dif = n - r;										//Definir diferencia
							if (dif >= 100) {									//Comprobar diferencia y visualizar el mensaje correspondiente
								printf("\nNo te has quedado ni cerca.");
							} else if (dif >= 50) {
								printf("\nTe has pasado, podrías apurar más.");
							} else if (dif >= 20) {
								printf("\nTe has pasado por poco.");
							} else if (dif >= 10) {
								printf("\nEstás cerca.");
							} else if (dif >= 5) {
								printf("\n¡Casi casi!");
							} else {
								printf("\n¡Imposible que falles!");
							}
						} else {												//Igual que el punto anterior
							dif = r - n;
							if (dif >= 100) {
								printf("\nNo te has quedado ni cerca.");
							} else if (dif >= 50) {
								printf("\nTe has pasado, podrías apurar más.");
							} else if (dif >= 20) {
								printf("\nTe has pasado por poco.");
							} else if (dif >= 10) {
								printf("\nEstás cerca.");
							} else if (dif >= 5) {
								printf("\n¡Casi casi!");
							} else {
								printf("\n¡Imposible que falles!");
							}
						}				
					cont++;														//Hacer que el contador de intentos vaya aumentando
					}									
				} while (n != r);							
				printf("\n¡Felicidades, has acertado el número!");		
				printf("\nEl número de intentos ha sido %d.", cont);
				printf("\n¿Quieres volver a intentarlo? (s/n): ");
		        fflush(stdin);
		        scanf("%c", &continuar2);
		        
			} while (continuar2 == 's' || continuar2 == 'S');
			printf("\nGracias por jugar a nuestro juego para el reto.\n");
			printf("\nQuieres volver al selector de juegos? (s/n)");
		    fflush(stdin);
		    scanf("%c", &reintentar);
		} else {
			printf("\nNo has elegido ningún juego.");
			printf("\nQuieres volver al selector de juegos? (s/n)");
		    fflush(stdin);
		    scanf("%c", &reintentar);
		}
	} while (reintentar == "s" || reintentar == "S");
	
	printf("\nGracias por jugar.");
}
