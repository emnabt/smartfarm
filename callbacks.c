#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "gestionderec.h"

//////////////////////////////validerreclamationCLIENT///////////////////////////////////////////////////
void
on_buttonvaliderrecclient_clicked      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *cli ,*recl ,*CIN ,*MSG ; 
char cin[20] ; 
char msg[1000] ; 


CIN=lookup_widget(objet_graphique,"entrycinrec");
MSG=lookup_widget(objet_graphique,"entryrecclient");

strcpy(cin,gtk_entry_get_text(GTK_ENTRY(CIN)));
strcpy(msg,gtk_entry_get_text(GTK_ENTRY(MSG)));

AjoutRec (cin,msg);

recl=lookup_widget(objet_graphique,"windowReclamationclient");
//cli=create_ClientWindow();
//gtk_widget_hide(recl);
//gtk_widget_show(cli);
}

////////////////////////////////annulerreclamationCLIENT/////////////////////////////////////////////////////////

void
on_buttonannulerecclient_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)

{
GtkWidget *cli ,*recl; 

recl=lookup_widget(objet_graphique,"windowReclamationclient");
//cli=create_ClientWindow();
//gtk_widget_hide(recl);
//gtk_widget_show(cli);
}


///////////////////////////reclamationsupprimée//////////////////////////////////////////////////////////////


void
on_buttonoksupprec_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowaffich;
GtkWidget *treeview1 ; 




windowaffich=create_windowrecsadmin();
gtk_widget_show (windowaffich);

treeview1=lookup_widget(windowaffich,"treeviewrecsadmin");
AfficherRec(treeview1);

}

////////////////////////affichagereclamationADMIN///////////////////////////////////////////////////////////////
void
on_buttonretourrecsadmin_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *admin ,*recl ; 

recl=lookup_widget(objet_graphique,"windowrecsadmin");
//admin=create_AdminWindow();
//gtk_widget_hide(recl);
//gtk_widget_show(admin);

}

/////////////////////////reclamationtraitée//////////////////////////////////////////////////////////////
void
on_buttonsupprec_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget  *refe ,*panier ,*suppok ,*text , *done ,*recl ; 
char cin[20] ;
refe=lookup_widget(objet_graphique,"entrycinrecadmin");
text=lookup_widget(objet_graphique,"entercinadmin");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(refe)));

if (strcmp(cin,"")==0) 
{
//gtk_label_set_text(GTK_LABEL(text),"Enter CIN ! ");
}

else 
{

suppRec(cin) ;

recl=lookup_widget(objet_graphique,"windowrecsadmin");
done=create_windowsupprectermine();
//gtk_widget_hide(recl);
//gtk_widget_show(done);
}
}




/*
void
on_buttonvaliderrecclient_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonannulerecclient_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonsupprec_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonoksupprec_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

}*/

