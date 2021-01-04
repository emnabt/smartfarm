
#include <gtk/gtk.h>


typedef struct 
{
char nom[50] ;
char prenom[50] ;
char sexe[20]; 
int d ;
int m;
int y ;
char cin[50];  
char tel[50];
char user[50] ;
char password[50];
char confpassword[50]; 
}Client ;



void AjoutRec (char cin[],char msg[]);
int AfficherRec (GtkWidget *liste);
void suppRec(char cin1[]);
