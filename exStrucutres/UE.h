struct activite_apprentissage
{
    char nom[100+1];
    int nbHeur;
    float note;

};

struct unite_enseignement
{

    struct activite_apprentissage activite[3];
    int nbCredit;
    char responsable[60+1];
    float cote;

};

struct unite_enseignement encodageUE(void);
struct activite_apprentissage encodeAA(void);

