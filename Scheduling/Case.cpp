#include <cstdio>
#include <cstdlib>
#include <ctime>

#include "SortList.cpp"
#include "priority.cpp"
#include "fifo.cpp"
#include "roundrobin.cpp"

int main(int argc, char const *argv[])
 {
   int opcion;

   do{
   puts("¿Que modalidad desea utilizar?\n1: FIFO\n2: SJF\n3: Round Robin\n4: Prioridad\n0: Salir\n\nOpción:");
   scanf("%i", &opcion);

   switch(opcion)
   {

      //FIFO
      case 1 :

         break;

      //SJF
      case 2 :

      /* Round Robin */
      case 3:

        break;
      /* Prioridad */
      case 4:

        break;

      /* Salir */
        case 0:

          return 0;
    {
    srand(time(NULL));
  int dato, cantdatos, prioridad, quantum;
  SortList *lista = new SortList();

  puts("Introduzca la cantidad de datos que desee generar para arreglar: ");
  scanf("%i",&cantdatos);

  int Milistado[cantdatos];
  int listaprioridad[cantdatos];

  for (int i = 0; i < cantdatos; ++i)
  {
    dato = rand() % 100+1;
    Milistado[i] = dato;
    bool Nnumber = lista->insert(dato);
    //printf("Posición %i: %i - Insertado: %i\n", i, dato, Nnumber);
  }

  for (int i = 0; i < cantdatos; ++i)
  {
    dato = rand() % 10+1;
    listaprioridad[i] = dato;
  }

    printf("\nListado: \n");
  for (int i = 0; i < cantdatos; ++i)
  {
  printf("Tiempo %i: %i -- Prioridad: %i \n", i, Milistado[i], listaprioridad[i]);
    }

  puts("\nResult: \nTiempos  Prioridad");
  lista->FinalOrder();
  puts("");

  delete lista;
    }
         break;

      //Round Robin
      case 3 :

         break;

      //Prioridad
      case 4 :

         break;

   }
   }while (opcion !=0);

   return 0;
}
