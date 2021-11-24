#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int ajt_compte (int nc,char nom[400][20],char prenom[400][20],char cin[400][10],double montant[400]);
void affichage(int nc,char nom[400][20],char prenom[400][20],char cin[400][10],double montant[400],double m);
void tri_asc(int nc,char nom[400][20],char prenom[400][20],char cin[400][10],double montant[400]);
void tri_desc(int nc,char nom[400][20],char prenom[400][20],char cin[400][10],double montant[400]);
int recherche(int nc,char nom[400][20],char prenom[400][20],char cin[400][10],double montant[400],char CIN[20]);

int main()
{
    int i,choix,n_cpt=0,c;
    char CIN[10];
    char nom[400][20],prenom[400][20],cin[400][10];
    double montant[400],m;
    int ch;

    do
    {

        printf("---Menu de Gestion des comptes bancaire-----\n\n");
        printf("1 - Introduire un compte bancaire \n");
        printf("2 - Introduire plusieurs compte bancaire\n");
        printf("3 - Les Operations\n");
        printf("4 - L\'Affichage / Recherche\n");
        printf("5 - Fidelisation\n");
        printf("6 - Quitter l\'application\n");
        printf("\n 		Choisir le numero de l\'operation a effectuer : ");
        scanf("%d",&ch);
        int ncpt,n;
        double s;
        switch (ch)
        {

        case 1 :
            n_cpt = ajt_compte(n_cpt,nom,prenom,cin,montant);
            break;

        case 2 :
            printf("Combien de compte vous voulez ajouter : ");
            scanf("%d",&c);
            for (i=0; i<c; i++)
            {
                n_cpt = ajt_compte(n_cpt,nom,prenom,cin,montant);
            }
            break;

        case 3 :
            printf("1 - Operation de retrait\n");
            printf("2 - operation de depot \n");
            printf("\nchoisir l\'operation souhaitable : ");
            scanf("%d",&choix);
            if(choix ==1)
            {
                printf("donner votre cin : ");
                scanf("%s",CIN);
                n=recherche(n_cpt,nom,prenom,cin,montant,CIN);
                if(n==-1)
                {
                    printf("Ce compte introuvable \n");
                    sleep(2);
                }
                if(n!=-1)
                {
                    printf("donner la somme que vous voulez retirer : ");
                    scanf("%lf",&s);
                    montant[n]-=s;
                    printf("le montant apres le retrait : %lf ",montant[n]);
                    sleep(3);
                }
            }
            if(choix == 2)
            {
                printf("donner voter cin : ");
                scanf("%s",CIN);
                n=recherche(n_cpt,nom,prenom,cin,montant,CIN);
                if(n==-1)
                {
                    printf("Ce compte n\'existe pas ...\n");
                    sleep(2);
                }
                if(n!=-1)
                {
                    printf("donner la somme que vous voulez ajouter : ");
                    scanf("%lf",&s);
                    montant[n]+=s;
                    printf("le montant apres le depot : %lf ",montant[n]);
                    sleep(3);
                }
            }

            break;
        case 4 :
            printf("1 - Affichage des comptes par ordre Ascendant\n");
            printf("2 - Affichage des comptes par ordre Descendant\n");
            printf("3 - Affichage des comptes par ordre Ascendant (ayant un montant sup a un chiffre introduit)\n");
            printf("4 - Affichage des comptes par ordre Descendant (ayant un montant inf a un chiffre introduit)\n");
            printf("5 - recherche par cin\n\n");
            printf("choisir entre le mode d\'affichage : ");
            scanf("%d",&choix);
            if(choix == 1)
            {
                printf("\n apres le tri ascendant des comptes : \n");
                tri_asc(n_cpt, nom,prenom,cin,montant);
                affichage(n_cpt,nom,prenom,cin,montant,0);
                sleep(13);
            }
            else if(choix == 2)
            {
                printf("\n Apres le tri descendant des comptes : \n");
                tri_desc(n_cpt, nom,prenom,cin,montant);
                affichage(n_cpt,nom,prenom,cin,montant,0);
                sleep(6);
            }
            else if(choix == 3)
            {
                printf("veuillez entrer un chiffre : ");
                scanf("%lf",&m);
                tri_asc(n_cpt, nom,prenom,cin,montant);
                affichage(n_cpt,nom,prenom,cin,montant,m);
                sleep(6);
            }
            else if(choix == 4)
            {
                printf("veuillez entrer un chiffre : ");
                scanf("%lf",&m);
                tri_desc(n_cpt, nom,prenom,cin,montant);
                affichage(n_cpt,nom,prenom,cin,montant,m);
                sleep(6);
            }
            else if(choix == 5)
            {
                printf("--------La recherche par CIN -------\n");
                printf("  Entrer le cin a chercher : ");
                scanf("%s",CIN);
                n=recherche(n_cpt,nom,prenom,cin,montant,CIN);
                if(n==-1)
                {
                    printf(" Ce compte n\'existe pas, veuillez Reesayer\n");
                    sleep(2);
                }
                else if(n!=-1)
                {
                    printf(" Ce compte est deja cree \n");
                    printf(" Le nom : %s\n Le prenom : %s\n Le montant actuel : %lf\n",nom[n],prenom[n],montant[n]);
                    sleep(5);
                }
            }
            break;
        case 5 : 	 	
			tri_asc(n_cpt, nom,prenom,cin,montant);
            printf("");
        	double m1 = montant[0];
        	double m2 = montant[0];
        	double m3 = montant[0];
            for(i=1; i<n_cpt; i++)
            {
                if(montant[i]>m1)
                {
                    m3=m2;
                    m2=m1;
                    m1=montant[i];

                }
                if(montant[i]<m1 && m2<montant[i])
                {
                    m3=m2;
                    m2=montant[i];
                }
                if(montant[i]<m2 && m3<montant[i])
                {
                    m3=montant[i];
                }
            }
            for(i=1; i<n_cpt; i++)
            {
                if(montant[i]>=m3)
                {
                    montant[i] = montant[i] + (montant[i]*1.3)/100;
                }
            }

            for(i=1; i<n_cpt; i++)
            {
                if(montant[i]>=m3)
                {
                    printf("\nLe cin  : %s \nle nom : %s\nle prenom : %s\nLe montant : %lf ",cin[i],nom[i],prenom[i],montant[i]);
                }
            }

            sleep(10);
            break;
        case 6 :
            printf("-------AU---REVOIR -------\n-----------MERCI-----------");
            sleep(2);
        }
        system("cls");
    }
    while(ch<=6);

    return 0;
}
int i,n_cpt;
int ajt_compte (int nc,char nom[400][20],char prenom[400][20],char cin[400][10],double montant[400])
{
    printf("Entrer les informations suivantes :\n");
    printf(" CIN :");
    scanf("%s",cin[nc]);
    printf(" Le nom : ");
    scanf("%s",nom[nc]);
    printf(" Le prenom :");
    scanf("%s",prenom[nc]);
    printf(" Le montant :");
    scanf("%lf",&montant[nc]);
    nc++;

    return nc;
}

void affichage(int nc,char nom[400][20],char prenom[400][20],char cin[400][10],double montant[400],double m)
{
    int i;
    for(i=0; i<nc; i++)
    {
        if(montant[i]>=m)
        {
            printf("CIN : %s | NOM : %s | PRENOM : %s | MONTANT : %lf\n",cin[i],nom[i],prenom[i],montant[i]);
        }
    }
}
void tri_asc(int nc,char nom[400][20],char prenom[400][20],char cin[400][10],double montant[400])
{
    char tmp[20];
    int ct;
    do
    {
        ct=0;
        double echange;
        for(i=0; i<nc-1; i++)
        {
            if(montant[i]>montant[i+1])
            {

                echange = montant[i];
                montant[i] = montant[i+1];
                montant[i+1] = echange;
                strcpy( tmp,nom[i]);
                strcpy( nom[i],nom[i+1]);
                strcpy( nom[i+1],tmp);
                strcpy( tmp,prenom[i]);
                strcpy( prenom[i],prenom[i+1]);
                strcpy( prenom[i+1],tmp);
                strcpy( tmp,cin[i]);
                strcpy( cin[i],cin[i+1]);
                strcpy( cin[i+1],tmp);
                ct++;
            }
        }
    }
    while(ct>0);
}
void tri_desc(int nc,char nom[400][20],char prenom[400][20],char cin[400][10],double montant[400])
{
    char tmp[20];
    int ct;
    do
    {
        ct=0;
        float echange;
        for(i=0; i<nc-1; i++)
        {
            if(montant[i]<montant[i+1])
            {

                echange = montant[i];
                montant[i] = montant[i+1];
                montant[i+1] = echange;
                strcpy( tmp,nom[i]);
                strcpy( nom[i],nom[i+1]);
                strcpy( nom[i+1],tmp);
                strcpy( tmp,prenom[i]);
                strcpy( prenom[i],prenom[i+1]);
                strcpy( prenom[i+1],tmp);
                strcpy( tmp,cin[i]);
                strcpy( cin[i],cin[i+1]);
                strcpy( cin[i+1],tmp);
                ct++;
            }
        }
    }
    while(ct>0);
}
int recherche(int nc,char nom[400][20],char prenom[400][20],char cin[400][10],double montant[400],char CIN[20])
{

    for (i=0; i<nc; i++)
    {
        if (strcmp(cin[i],CIN) == 0)
        {
            return i;
        }
    }
    return -1;
}

