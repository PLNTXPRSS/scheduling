#include <cstdio>
#include <cstdlib>
#include <ctime>

#include "SortList.cpp"
#include "FIFO.cpp"
#include "RoundRobin.cpp"
#include "Prioridad.cpp"

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
      {
            srand(time(NULL));
	int dato, cantdatos, prioridad;
	int promedio = 0;
	FIFO *listaF = new FIFO();

	puts("Introduzca la cantidad de datos que desee generar para arreglar: ");
	scanf("%i",&cantdatos);

	int Milistado[cantdatos];
	int listaprioridad[cantdatos];

	for (int i = 0; i < cantdatos; ++i)
	{
		dato = rand() % 29+1;
        prioridad = rand() % 5 + 1;
		Milistado[i] = dato;
		listaprioridad[i] = prioridad;
		bool Nnumber = listaF->insert(dato, prioridad);
        promedio += Milistado[i];
	}

    printf("\nListado: \n");
	for (int i = 0; i < cantdatos; ++i)
	{
	printf("Tiempo %i: %i -- Prioridad: %i \n", i, Milistado[i], listaprioridad[i]);
    }

	puts("\nResult: \nTiempos  Prioridad");
	listaF->FinalOrderF();
	puts("");

	delete listaF;
    }
         break;

      //SJF
      case 2 :
    {
    srand(time(NULL));
	int dato, cantdatos, prioridad;
	int promedio = 0;
	SortList *lista = new SortList();

	puts("Introduzca la cantidad de datos que desee generar para arreglar: ");
	scanf("%i",&cantdatos);

	int Milistado[cantdatos];
	int listaprioridad[cantdatos];

	for (int i = 0; i < cantdatos; ++i)
	{
		dato = rand() % 4+1;
        prioridad = rand() % 5 + 1;
		Milistado[i] = dato;
		listaprioridad[i] = prioridad;
		bool Nnumber = lista->insert(dato, prioridad);
        promedio += Milistado[i];
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
         {
         srand(time(NULL));
         int dato, cantdatos, prioridad, quantum;
         int promedio = 0;
         RoundRobin *listaR = new RoundRobin();

         puts("Introduzca la cantidad de datos que desee generar para arreglar: ");
         scanf("%i",&cantdatos);

         int Milistado[cantdatos];
         int listaprioridad[cantdatos];

         for (int i = 0; i < cantdatos; ++i)
         {
            dato = rand() % 29+1;
            quantum += dato;
            prioridad = rand() % 5 + 1;
            Milistado[i] = dato;
            listaprioridad[i] = prioridad;
            bool Nnumber = listaR->insert(dato, prioridad);
            promedio += Milistado[i];
         }
         quantum = quantum / cantdatos;
         bool NQuant = listaR->insertquantum(quantum);

         printf("\nListado: \n");
         for (int i = 0; i < cantdatos; ++i)
         {
            printf("Tiempo %i: %i -- Prioridad: %i \n", i, Milistado[i], listaprioridad[i]);
         }
         printf("Quantum: %i\n", quantum);

         listaR->FinalOrderR();
         puts("");

         delete listaR;
         }
         break;

      //Prioridad
      case 4 :
        {
          Prioridad *p = new Prioridad();
            for (int i = 1; i < 11; ++i) {
              printf("ID: %i \tTiempo: %i \tPrioridad: %i\n", i, i, i);
              p->Insertar(i, i);
            }
            p->print_all();
            //p->print_all();

        }
        break;

      case 0 :
         puts("Cierre");
         break;

      default:
         puts("Opcion Invalida\n");
         break;

   }
   }while (opcion !=0);

   return 0;
}
