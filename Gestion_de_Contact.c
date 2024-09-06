// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

typedef struct {
    char nom[10];
    char tele[50];
    char email[50];
} contact ;

int len = 0;

contact contacts[100];

void saisir(){
    printf("Entrer votre nom :");
    scanf("%s",contacts[len].nom);
    printf("Entrer votre tele :");
    scanf("%s",contacts[len].tele);
    printf("Entrer votre email :");
    scanf("%s",contacts[len].email);
    len++;
}

void menuDeChoix(){
    printf("1. Ajouter un Contact :\n");
    printf("4. Afficher Tous les Contacts:\n");
    printf("2. Modifier un Contact :\n");
    printf("3. Supprimer un Contact :\n");
    printf("5. Rechercher un Contact :\n");
    printf("6. Quitter:\n");
}

void affichageLesInformation(){
    for(int i = 0; i <len; i++){
        printf("%d => Nom: %s\n", i + 1, contacts[i].nom);
        printf("%d => Tele: %s\n", i + 1, contacts[i].tele);
        printf("%d => Email: %s\n", i + 1, contacts[i].email);
    }
}

int Search(){
    char s[100];
    printf("Saisir le caracter pour vous search :");
    scanf("%s",&s);

    for(int i=0;i<len;i++){
        if(strcmp(contacts[i].nom,s)==0){
            return i;
         }
    }
   
    return -1;
 }
 
 void saisirNewInformation(){
    char Nnom[50];
    char Ntele[50];
    char Nemail[50];
   
    int indice = Search();
   
    if(indice == -1){
        printf("Contact n'exist pas!");
        return;
    }
   
    printf("Entrer nouvelle votre nom :");
    scanf("%s",Nnom);
    printf("Entrer nouvelle votre tele :");
    scanf("%s",Ntele);
    printf("Entrer nouvelle votre email :");
    scanf("%s",Nemail);
   
    strcpy(contacts[indice].nom, Nnom);
    strcpy(contacts[indice].tele, Ntele);
    strcpy(contacts[indice].email, Nemail);
   
}

    void SuppritionContact(){
        char titleS[50];
        printf("Entrer un title pour vous supprimer");
        scanf("%s",titleS);
        
        int indice = -1;
        for(int i=0;i<len;i++){
            if(strcmp(contacts[i].nom,titleS)==0){
                 indice = i;
                 break;
             }
        }
        
        if(indice == -1){
            printf("countact n'est trouve pas");
            return;
        }
        
        for(int i=indice;i<len;i++){
            contacts[i] = contacts[i + 1];
        }
        len--;
    }
    void menu(){
        int choix;
        menuDeChoix();
        printf("Entrer votre choix :");
        scanf("%d",&choix);
       
        switch(choix){
            case 1:
                saisir();
                menu();
                break;
            case 2:
                affichageLesInformation();
                menu();
                break;
            case 3:
                saisirNewInformation();
                menu();
                break;
            case 4:
                SuppritionContact();
                menu();
                break;
        }
    }
int main() {
    menu();
    return 0;
}