#include <urdu.h>


int main(void)
{
    likhde_line("===============================================");
    likhde_line("           UrduC Interactive Demo");
    likhde_line("===============================================\n");

    likhde_line("Assalam-o-Alaikum! \n");

    char naam[100];
    int umar = parhle_int("Apni umar likho: ");
    parhle("Apna naam likho: ", naam, sizeof(naam));

    likhde("\kese ho  ");
    likhde(naam);
    likhde_line("!");
    likhde("Aap ki umar hai: ");
    likhde_int_line(umar);

    agr (umar < 18)
        likhde_line("Aap abhi chhotay hain!");
    warna_agr (umar < 50)
        likhde_line("Aap ab barey hogai ho!");
    warna
        likhde_line("Aap to bohat barey hain!");

    likhde_line("\n--- STRING FUNCTIONS DEMO ---");

    char s1[100], s2[100], result[200];
    parhle("Pehli string likho: ", s1, sizeof(s1));
    parhle("Dusri string likho: ", s2, sizeof(s2));

    likhde_line("\nNakal (Copy) demo:");
    nakal(result, s1);
    likhde("humne pehli string ko dusri mein daldiya: ");
    likhde_line(result);

    likhde_line("\nJodo (Concatenate) demo:");
    jodo(result, " ");
    jodo(result, s2);
    likhde("Dono strings mil kar ban gayi: ");
    likhde_line(result);

    likhde_line("\nMuqabla (Compare) demo:");
    int cmp = muqabla(s1, s2);
    agr (cmp == 0)
        likhde_line("Dono strings barabar hain!");
    warna_agr (cmp < 0)
        likhde_line("Pehli string chhoti hai.");
    warna
        likhde_line("Pehli string badi hai.");

    likhde_line("\nLambai (Length) demo:");
    likhde("Pehli string ki lambai: ");
    likhde_int_line(lambai(s1));
    likhde("Dusri string ki lambai: ");
    likhde_int_line(lambai(s2));

    // --- CHARACTER FUNCTIONS DEMO ---
    likhde_line("\n--- CHARACTER FUNCTIONS DEMO ---");
    char ch;
    likhde("Koi ek character likho: ");
    scanf(" %c", &ch);

    likhde("Bara karo (toupper): ");
    likhde_harf_line(bara_karo(ch));
    likhde("Chhota karo (tolower): ");
    likhde_harf_line(chhota_karo(ch));

    agr (kya_harf(ch))
        likhde_line("Yeh ek huroof hai.");
    warna_agr (kya_adad(ch))
        likhde_line("Yeh ek number hai.");
    warna
        likhde_line("Yeh na hi huroof hai na hi koi number.");

    getchar(); 

    likhde_line("\n--- FILE HANDLING DEMO ---");

    char filename[100];
    parhle("File ka naam likho (e.g., mera_data.txt): ", filename, sizeof(filename));

    FILE *meraFile = file_kholo(filename, "w");
    agr (meraFile == NULL) {
        likhde_line("File likhne mein masla aya!");
        return 1;
    }

    likhde_line("\nFile mein kuch likho:");
    char fileContent[300];
    parhle("", fileContent, sizeof(fileContent));

    line_likho(fileContent, meraFile);
    file_band(meraFile);

    likhde_line("\nFile likh di gayi!");

    likhde_line("\nKya aap file mein aur data jorna chahtay hain? (Y/N): ");
    char choice;
    scanf(" %c", &choice);
    getchar(); 

    agr (choice == 'Y' || choice == 'y') {
        FILE *appendFile = file_kholo(filename, "a");
        agr (appendFile == NULL) {
            likhde_line("File append karte waqt masla aya!");
            return 1;
        }

        likhde_line("File mein aur likho:");
        char extraContent[300];
        parhle("", extraContent, sizeof(extraContent));

        line_likho("\n", appendFile);
        line_likho(extraContent, appendFile);
        file_band(appendFile);

        likhde_line("Naya data successfully jor diya gaya!");
    }

    likhde_line("\nFile ka final content padhte hain:");
    FILE *readFile = file_kholo(filename, "r");
    agr (readFile == NULL) {
        likhde_line("File padhne mein masla aya!");
        return 1;
    }

    char line[300];
    jab_tak (line_lo(line, sizeof(line), readFile) != NULL) {
        likhde(line);
    }
    file_band(readFile);

    likhde_line("\n\n--- LOOP DEMO ---");
    int count = parhle_int("Kitni martaba likhna hai 'Pakistan Zindabad'? : ");
    int i = 0;

    jab_tak (i < count) {
        likhde_line("Pakistan Zindabad!");
        i++;
    }

    likhde_line("\nDemo mukammal hogaya!");
    likhde_line("Shukriya! Allah Hafiz.");

    return 0;
}


