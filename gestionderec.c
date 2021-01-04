#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"gestionderec.h"
#include <gtk/gtk.h>

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif




////////////////////////gestion de reclamation /////////////////////////////////////////////////////////////////////////////////////////////////

/*************************************************************************************************************/
/*************************************************************************************************************/
//ajouter reclamation------------------------------------------------------

void AjoutRec (char cin[],char msg[])
{
FILE *f;
f=fopen("src/Recs.txt","a");
if(f!=NULL)
{fprintf(f,"%s %s \n",cin,msg);
fclose(f);
}
}


enum {
CINR,
MSGR,
COLUMNSR
} ; 

/*************************************************************************************************************/
/*************************************************************************************************************/

//afficher reclamation-----------------------------------------------------------------------------------------

int AfficherRec (GtkWidget *liste)
{
	GtkCellRenderer *renderer;  //envoyer la saisir de l'utilisateur de 		chaque champ 
	GtkTreeViewColumn *column;//correspendre le contenue du champ a son 		attribue de la liste
	GtkTreeIter   iter;    //itterateur sur l'ensemble des elements de 		treeview
	GtkListStore  *store;    //l'enregistrement de treeview

char cin[20]; 
char msg[50]; 


store=NULL ; 
FILE* f ; 

store=gtk_tree_view_get_model(liste) ; 
if (store==NULL) 
{
render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("CIN",render,"text",CINR,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 


render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("Reclamation",render,"text",MSGR,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 



store=gtk_list_store_new(COLUMNSR,G_TYPE_STRING,G_TYPE_STRING) ; 

f=fopen("src/Recs.txt","r") ; 
if (f==NULL) 
{
return ; 
}
else 
{
f=fopen("src/Recs.txt","a+") ;
 while(fscanf(f,"%s %s \n" ,cin,msg)!=EOF) 
{
gtk_list_store_append (store,&iter) ; 
gtk_list_store_set (store,&iter,CINR,cin,MSGR,msg,-1) ; 
}
fclose(f) ;} 
gtk_tree_view_set_model(GTK_TREE_VIEW (liste),GTK_TREE_MODEL (store)); 
g_object_unref (store) ; 

}
}

/*************************************************************************************************************/
/*************************************************************************************************************/

//suppremier reclamation------------------------------------------------

void suppRec(char cin1[])
{

FILE *f;
FILE *f1;
char cin[20]; 
char msg[20]; 

int r;
f=fopen("src/Recs.txt","r");
f1=fopen("src/Recs1.txt","w");
if (f!=NULL){
    if(f1!=NULL){
while(fscanf(f,"%s %s \n" ,cin,msg)!=EOF ) {
    if(strcmp(cin1,cin)!=0){
        fprintf("%s %s \n" ,cin,msg);
        r=1;
    }
}
    }
    fclose(f1);
}

fclose(f);
if (r){
	
	remove ("src/Recs.txt");
	rename ("src/Recs1.txt","src/Recs.txt");
	}

}


