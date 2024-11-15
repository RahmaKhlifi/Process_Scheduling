#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<conio.h>
#include<windows.h>

typedef struct process process;
     struct process {
                  int PID ;
                  int TA;
                  int TE ;
                  int TF ;
                  int tta;
                  int duree;
                  struct process *next ;
                };

//--------------------------------------------------------declaration d'un process
process* init();
process* Saisie_process();
void affichage_process();
void menu(process *p);
void tri_process(process *p);
void FIFO_process(process *p);
void RR_process(process *p);
void diag_grantt(process *p);
process* copy_process(process *p);
void parcourt(process *p , int q);
void algo_RR () ;
 void RR_process(process *p);
 int get_positive_int(const char* prompt);
 void cleanup_processes(process* p) ;

//--------------------------------------------------
void reset ();
//---------------------------------------------------------main prog:

int main() {
    process* p = NULL;  
    menu(p);
    if (p != NULL) {
        cleanup_processes(p);
    }
    return 0;
}


//---------------------------------------------------


void menu(process* p) {
    int choix;
    system("color");
    printf("\033[0;31m");
    printf("  \n\n ********* Bienvenue dans notre algorithme d'ordonnancement pour le FIFO et le RR ********** \n");
    printf("\033[0m");
    printf("  \n ******************* Author: Khlifi Rahma********************** \n");
    printf("______________________________________________________________________________________________________________\n\n");
    choix = get_positive_int("  Pour appliquer le FIFO choisissez 1, pour appliquer le RR choisissez 2, pour appliquer le RR avec liste chainee choisissez 3 : ");

    switch (choix) {
        case 1:
            p = Saisie_process();
            printf(" Le tableau trié est :\n");
            tri_process(p);
            affichage_process(p);
            FIFO_process(p);
            diag_grantt(p);
            break;
        case 2:
            algo_RR();
            break;
        case 3:
            p = Saisie_process();
            printf(" Le tableau trié est :\n");
            tri_process(p);
            affichage_process(p);
            RR_process(p);
            break;
        default:
            printf("Erreur de saisie\n");
            break;
    }

    if (p != NULL) {
        cleanup_processes(p);
        p = NULL;
    }
}

//--------------------------------------------------------------------------------------------------------------------------

process* init() {
    process* p = (process*)malloc(sizeof(process));
    p->PID = -1;
    p->TA = p->TE = p->TF = p->tta = p->duree = 0;
    p->next = NULL;
    return p;
}
//------------------------------------------------------------------------------------------------------
void cleanup_processes(process* p) {
    process* temp;
    while (p != NULL) {
        temp = p;
        p = p->next;
        free(temp);
    }
}

//-----------------------------------------------------------------------------------------------------------------------
int get_positive_int(const char* prompt) {
    int value;
    do {
        printf("%s", prompt);
        if (scanf("%d", &value) != 1) {
            printf("Invalid input. Please enter a positive integer.\n");
            while (getchar() != '\n');  // Clear input buffer
        }
    } while (value <= 0);
    return value;
}

//---------------------------------------------------------------------------------------------------------
process* Saisie_process(){
    int n = get_positive_int("Merci de saisir le nombre de processus : ");
    process *p;
    process *nv;
    process *temp;
    init();
    p=malloc(sizeof(process));
    p->PID = 0;
    system("color");
    printf("\033[0;34m");
    p->TA = get_positive_int("Veuillez saisir le temps d'arrivee de processus : ");
    p->TE = get_positive_int("Veuillez saisir le temps d'Execution de processus : ");
    p->next=NULL;
     int i = 1;
     temp=p;
   while(i<n){
    nv=malloc(sizeof(process));
    nv->PID = i;
    system("color");
    printf("\033[0;34m");
    printf("  Veuillez saisir le temps d'arrivee de processus: ");
    scanf("%d",&(nv->TA));
    printf("  Veuillez saisir le temps d'execution de processus: ");
    scanf("%d",&(nv->TE));
    printf("\033[0m");
    nv->next=NULL;
    temp->next=nv;
    temp=temp->next;
    i++;

    } ;
    return p ;



 }
//----------------------------------------------------------------------------------------------

void affichage_process(process *p){
    printf("\033[0;32m");
   printf ("  +--------------------------------------------------+\n");
   reset();
   printf ("  |  PID  |  temps d'arrivee   |   Temps d'execution |\n");
    printf("\033[0;32m");
   printf ("  +-------+--------------------+---------------------+\n");
   reset();
   while (p!=NULL)
    {
   printf ("  |  P%d   |         %d          |          %d          |\n",p->PID,p->TA,p->TE);
   printf("\033[0;32m");
   printf ("  +-------+--------------------+---------------------+\n");
   reset();
            p=p->next;
          }
}
//-----------------------------------------------------------------------------------------------------
void tri_process(process *p){
    process *q;
    process *d ;
    int aux1,aux2;
    bool test ;
    if (p!=NULL && (p->next)!=NULL){
        do{
            test=false;
            q=p;
            d=p->next;
            while(d!=NULL){
                if((q->TA)>(d->TA)){
                    test=true;
                    aux1=q->TA;
                    q->TA=d->TA;
                    d->TA=aux1;
                    aux2=q->TE;
                    q->TE=d->TE;
                    d->TE=aux2;
                }
                q=q->next;
                d=d->next;
            }
        }while(test==true);
    }

}
//----------------------------------------------------------------------------------------------------------------
void FIFO_process(process *p){
               tri_process(p);
               system("color");
               printf("\033[0;35m");
           printf( "       \n\n\n               -----------------------------------------------------------------------------\n");
               printf ("               |   ALGORITHME D'ORDONNANCEMENT EN APPLIQUANT LE FIFO (FIRST IN FIRST OUT)  |\n");
                printf( "               -----------------------------------------------------------------------------\n");
                 printf("\033[0m");
               float tr=p->TE;
               float ta=0;
               int tf=p->TE;
               int i=1;
               process *q=p->next;
                while(q!=NULL)
                    {
                    tr=tr+tf+(q->TE)-q->TA;
                    ta=ta+tf+(q->TE)-q->TA-(q->TE);
                    i++;
                    tf=tf+q->TE;
                    q=q->next;
                };

              tr=tr/i;
              ta=ta/i;
              system("color");
              printf("\033[0;33m");
              printf("                                   Le temps de rotation moyen est : %f\n\n",tr);
              printf("                                   Le temps d'attente moyen est : %f\n\n",ta);
               reset();
   }


 //-------------------------------------------------------------------------------------------------------------------
void reset () {
  printf("\033[0m");
}
//---------------------------------------------------------------------------------------------------------
void diag_grantt(process *p){
    system("color");
    printf("\033[0;36m");
    printf("                   **********************   Diagramme de Grantt   **********************         \n\n");
    reset();
    tri_process(p);
    process *q=p;
    printf("             ");
    while(q!=NULL)
    {
         int i=0;
        while(i<q->TE)
        {
            printf("|  P%d  |",q->PID);
            i++;
        }
        q=q->next;
    }
    printf("\n\n");



}
//----------------------------------------------------------------------------------------------------------------
process* copy_process(process *p)
{
    process *nv;
    process *q ;
    q=malloc(sizeof(process));
    q->PID = p->PID;
    q->TA = p->TA;
    q ->TE=p->TE;
    q->next=NULL;
    process *temp=q;
    process *d=p->next;
   while(d!=NULL){
    nv=malloc(sizeof(process));
    nv->PID = d->PID;
    nv->TA = d->TA;
    nv ->TE=d->TE;
    nv->next=NULL;
    temp->next=nv;
    temp=temp->next;
    d=d->next;
    } ;
    return q ;
}
//----------------------------------------------------------------------------------------------------------------
void tri_process_f(process *p){
   int aux1 , aux2 ,aux3 , aux4 , aux5 , aux6 ;
   process *d , *q ;
    if (p!=NULL && (p->next)!=NULL){
            q=p;
            d=p->next;
            while(d!=NULL){
                if((q->tta)>=(d->tta)){
                    aux1=q->tta;
                    q->tta=d->tta;
                    d->tta=aux1;

                    aux2=q->TE;
                    q->TE=d->TE;
                    d->TE=aux2;

                     aux3=q->TA;
                    q->TA=d->TA;
                    d->TA=aux3;

                     aux4=q->TF;
                    q->TF=d->TF;
                    d->TF=aux4;

                     aux5=q->duree;
                    q->duree=d->duree;
                    d->duree=aux5;

                     aux6=q->PID;
                    q->PID=d->PID;
                    d->PID=aux6;


                }
                q=q->next;
                d=d->next;
            };
   };

}
//-----------------------------------------------------------------------------------------------------------------
void RR_process(process *p)
{
    float tr,ta;
    int e;
    int n=0;
    tri_process(p);
    process *q=copy_process(p);
    process *d=q;
    process *j;
               system("color");
               printf("\033[0;35m");
               printf( "       \n\n\n               -----------------------------------------------------------------------------\n");
               printf ("               |      ALGORITHME D'ORDONNANCEMENT EN APPLIQUANT LE RR ( ROUND ROBIN )       |\n");
                printf( "               -----------------------------------------------------------------------------\n");
                 printf("\033[0m");
                 printf("\n");
                 int Q ;
    Q=get_positive_int("Veuillez saisir le quantum :");
    system("color");
    printf("\033[0;36m");
    printf("\n\n                   **********************   Diagramme de Grantt   **********************         \n\n");
    reset();
    while(d!=NULL)
    {
        d->TF=0;
        d->duree=d->TE;
        d->tta=d->TA;
        n++;
        d=d->next;

    };
    d=q;
    while (d!=NULL)
    {
      if(d->TE==0)
        d=d->next;
      else
        if((d->TE)>=Q)
        {
          printf("|  P%d (2s)  |",d->PID);
          d->tta=d->tta+Q;
          d->TE=(d->TE)-Q;
         parcourt(d , Q);
          tri_process_f(d);
         }
      else if ((d->TE)<Q)
        {
         printf("|  P%d (1s) |",d->PID);
         d->tta=d->tta+d->TE;
         parcourt(d ,d->TE );
          d->TE=0;
          tri_process_f(d);
      };
    };
    d=q;
    tr=0;
    ta=0;
    while(d!=NULL)
    {
      tr=tr+(d->TF)-(d->TA);
      ta=ta+tr-(d->duree);
      d=d->next;

    };
    tr=tr/n;
    ta=ta/n;
    system("color");
              printf("\033[0;33m");
              printf("\n\n                                   Le temps de rotation moyen est : %f\n\n",tr);
              printf("                                   Le temps d'attente moyen est : %f\n\n",ta);
               reset();
}
void parcourt(process *p , int q)
{
    process *d=p;
    while (d!=NULL)
    {
        if(d->TE != 0)
        d->TF=d->TF+q;

       d=d->next;
    };
}
void algo_RR ()

{      system("cls()");
       system("color");
               printf("\033[0;35m");
               printf( "       \n\n\n               -----------------------------------------------------------------------------\n");
               printf ("               |      ALGORITHME D'ORDONNANCEMENT EN APPLIQUANT LE RR ( ROUND ROBIN )       |\n");
                printf( "               -----------------------------------------------------------------------------\n");
                 printf("\033[0m");
                 printf("\n");

    int i, nbr_P, sum=0, count=0, y, quant, wt=0, tat=0, ar[10], ex[10], temp[10];
    float avg_wt, avg_tat;
    printf(" Totale nbr de processus dans le systeme : ");
    scanf("%d", &nbr_P);
    y = nbr_P;


     for(i=0; i<nbr_P; i++)
    {
      printf("\n donner le temp d'arrivee et temp d'execution du processus [%d]\n", i+1);
      printf(" temp d'arrivee: \t");
      scanf("%d", &ar[i]);
       printf(" \ntemp d'execution: \t");
     scanf("%d", &ex[i]);
      temp[i] = ex[i];
}

quant = get_positive_int("donner le quantum :");


printf("\n Process No \t\t temp_execution \t\t temp_attente ");
for(sum=0, i = 0; y!=0; )
{
if(temp[i] <= quant && temp[i] > 0)
{
    sum = sum + temp[i];
    temp[i] = 0;
    count=1;
    }
    else if(temp[i] > 0)
    {
        temp[i] = temp[i] - quant;
        sum = sum + quant;
    }
    if(temp[i]==0 && count==1)
    {
        y--;
        printf("\nProcess No[%d] \t\t            %d\t\t\t %d", i+1, ar[i],  sum-ar[i]-ex[i]);
        wt = wt+sum-ar[i]-ex[i];
        tat = tat+sum-ar[i];
        count =0;
    }
    if(i==nbr_P-1)
    {
        i=0;
    }
    else if(ar[i+1]<=sum)
    {
        i++;
    }
    else
    {
        i=0;
    }
}}
//--------------------------------------------------------------------------------------------------------
