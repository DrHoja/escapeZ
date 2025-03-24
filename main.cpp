#include <iostream>
#include <string>
#include <limits>
#include <chrono>
#include <thread>
#include <sstream>
#include <map>
#include <algorithm>
#include <atomic>

using namespace std;

const string guion[0];//colocar aquí todos los diálogos al final.

map<string, int>est;//listado de objetos y su clasificación
map<string, int>obj={
    //basura
    {"basura", 0},
    // Alimentos = 1
    {"arroz", 1},
    {"frijoles", 1},
    {"maíz", 1},
    //{"maiz",0},
    {"papas", 1},
    {"yuca", 1},
    {"camote", 1},
    {"plátano", 1},
    {"aguacate", 1},
    {"tomate", 1},
    {"cebolla", 1},
    {"ajo", 1},
    {"chile", 1},
    {"cilantro", 1},
    {"limón", 1},
    {"naranja", 1},
    {"mango", 1},
    {"piña", 1},
    {"café", 1},
    {"azúcar", 1},
    {"sal", 1},
    {"aceite", 1},
    {"pan", 1},
    {"tortilla", 1},
    // Proteínas = 2
    {"carne de res", 2},
    {"carne", 2},
    {"pollo", 2},
    {"pescado", 2},
    {"cerdo", 2},
    {"huevos", 2},
    {"leche", 2},
    {"queso", 2},
    // Utensilios = 3
    {"olla", 3},
    {"sarten", 3},
    {"tenedor", 3},
    {"cuchara", 3},
    {"plato", 3},
    {"vaso", 3},
    {"taza", 3},
    // Ropa = 4
    {"camisa", 4},
    {"pantalon", 4},
    {"zapatos", 4},
    {"vestido", 4},
    {"sombrero", 4},
    // Hogar = 5
    {"mesa", 5},
    {"silla", 5},
    {"cama", 5},
    {"televisor", 5},
    // Electrónicos = 6
    {"radio", 6},
    {"telefono", 6},
    {"computadora", 6},
    {"libro", 6},
    {"lampara", 6},
    // Transporte = 7
    {"autobus", 7},
    {"carro", 7},
    {"bicicleta", 7},
    // Moneda = 8
    {"dinero", 8},
    // Medicinas = 9
    {"medicamentos", 9},
    // herramientas = 10
    {"herramientas", 10},
    {"alicates", 10},
    {"almagana", 10},
    {"azada", 10},
    {"azadón", 10},
    {"berbiquí", 10},
    {"caja de herramientas", 10},
    {"cepillo de carpintero", 10},
    {"cincel", 10},
    {"cortafrío", 10},
    {"cortatubos", 10},
    {"crique", 10},
    {"cutter", 10},
    {"desarmador", 10},
    {"desatascador", 10},
    {"destornillador", 10},
    {"destornilladores", 10},
    {"escalera", 10},
    {"escuadra", 10},
    {"espátula", 10},
    {"formon", 10},
    {"goniómetro", 10},
    {"gato hidráulico", 10},
    {"guadaña", 10},
    {"hoz", 10},
    {"horqueta", 10},
    {"juego de llaves allen", 10},
    {"llave ajustable", 10},
    {"llave inglesa", 10},
    {"llave stillson", 10},
    {"martillo", 10},
    {"martillo de bola", 10},
    {"martillo de goma", 10},
    {"mazo", 10},
    {"mordaza", 10},
    {"nivel", 10},
    {"pala", 10},
    {"pala de jardín", 10},
    {"pala de punta", 10},
    {"palanca", 10},
    {"pelacables", 10},
    {"pico", 10},
    {"pie de rey", 10},
    {"pinzas", 10},
    {"plomada", 10},
    {"podadora de altura", 10},
    {"rascador", 10},
    {"rastrillo", 10},
    {"regla metalica", 10},
    {"rodillo", 10},
    {"sargento", 10},
    {"segueta", 10},
    {"serrucho", 10},
    {"sierra", 10},
    {"sierra circular", 10},
    {"sierra para metales", 10},
    {"soplete", 10},
    {"taladro", 10},
    {"taladro eléctrico", 10},
    {"taladro percutor", 10},
    {"tenazas", 10},
    {"tijeras", 10},
    {"tijeras de electricista", 10},
    {"tijeras de injerto", 10},
    {"tijeras de podar", 10},
    {"transportador", 10},
    // Higuiene = 11
    {"jabón", 11},
    // oficina = 12
    {"papel", 12},
    {"lapiz", 12},
    {"cuaderno", 12},
    // Cortantes = 13
    {"cuchillo", 13},
    // Armas = 14
    {"pistola",14},
    // Explosivos = 15
    {"granada",15},
    //etc.
};

const string tipos[17]={//listado de clasificaciones de objeto
    "basura", // 0
    "Alimentos", // 1
    "Proteínas", // 2
    "Utensilios", // 3
    "Ropa", // 4
    "Hogar", // 5
    "Electrónicos", // 6
    "Transporte", // 7
    "Moneda", // 8
    "Medicinas", // 9
    "herramientas", // 10
    "Higiene", // 11
    "oficina", // 12
    "Cortantes", // 13
    "Armas", // 14
    "Explosivos", // 15
    "etc"};// 16

    const int total=200;
    const string cosas[total]={ //lista de objetos array
        // Basura = 0
        // Alimentos = 1
        "arroz",
        "frijoles",
        "maíz",
        "papas",
        "yuca",
        "camote",
        "plátano",
        "aguacate",
        "tomate",
        "cebolla",
        "ajo",
        "chile",
        "cilantro",
        "limón",
        "naranja",
        "mango",
        "piña",
        "café",
        "azúcar",
        "sal",
        "aceite",
        "pan",
        "tortilla",
        // Proteínas = 2
        "carne de res",
        "carne"
        "pollo",
        "pescado",
        "cerdo",
        "huevos",
        "leche",
        "queso",
        // Utensilios = 3
        "olla",
        "sarten",
        "tenedor",
        "cuchara",
        "plato",
        "vaso",
        "taza",
        // Ropa = 4
        "camisa",
        "pantalon",
        "zapatos",
        "vestido",
        "sombrero",
        // Hogar = 5
        "mesa",
        "silla",
        "cama",
        "televisor",
        // Electrónicos = 6
        "radio",
        "telefono",
        "computadora",
        "libro",
        "lampara",
        // Transporte = 7
        "autobus",
        "carro",
        "bicicleta",
        // Moneda = 8
        "dinero",
        // Medicinas = 9
        "medicamentos",
        // herramientas = 10
        "herramientas",
        "alicates",
        "almagana",
        "azada",
        "azadón",
        "berbiquí",
        "caja de herramientas",
        "cepillo de carpintero",
        "cincel",
        "cortafrío",
        "cortatubos",
        "crique",
        "cutter",
        "desarmador",
        "desatascador",
        "destornillador",
        "destornilladores",
        "escalera",
        "escuadra",
        "espátula",
        "formon",
        "goniómetro",
        "gato hidráulico",
        "guadaña",
        "hoz",
        "horqueta",
        "juego de llaves allen",
        "llave ajustable",
        "llave inglesa",
        "llave stillson",
        "martillo",
        "martillo de bola",
        "martillo de goma",
        "mazo",
        "mordaza",
        "nivel",
        "pala",
        "pala de jardín",
        "pala de punta",
        "palanca",
        "pelacables",
        "pico",
        "pie de rey",
        "pinzas",
        "plomada",
        "podadora de altura",
        "rascador",
        "rastrillo",
        "regla metalica",
        "rodillo",
        "sargento",
        "segueta",
        "serrucho",
        "sierra",
        "sierra circular",
        "sierra para metales",
        "soplete",
        "taladro",
        "taladro eléctrico",
        "taladro percutor",
        "tenazas",
        "tijeras",
        "tijeras de electricista",
        "tijeras de injerto",
        "tijeras de podar",
        "transportador",
        // Higuiene = 11
        "jabón",
        // oficina = 12
        "papel",
        "lapiz",
        "cuaderno",
        // Cortantes = 13
        "cuchillo",
        // Armas = 14
        "pistola",
        // Explosivos = 15
        "granada"
        //etc.
    };

    const string esp[4] = {"bolsa grande vacía","bolsa pequeña vacía","bolsillo derecho vacío","bolsillo izquierdo vacío"};
    string mochila[4];
    string sino;//entrada de respuesta
    string objeto;//entrada de texto a evaluar
    string correcto[4];//opciones correctas
    string gxx;//mensaje de error al usar objeto
    string txx;//texto de error
    const string r[6]={"si","Si","SI","no","No","NO"};//respuestas posibles
    int respuesta;//
    int o;//contador de objeto
    int e;//contador de errores
    int c;//contador de intentos
    int t;//tiempo
    int m;//numero de espacio en la mochila
    const int v=60;//velocidad del dialogo
    const int V=40;//dialogo rápido
    const int w=200;//velocidad de texto
    const int W=150;//testo rápido
    int seg=1;//un segundo
    bool bad;//mantener bucle
    bool ok;//respuesta correcta
    bool op[4];//bandera de objeto correcto
    atomic<bool> tiempo(false);//notificador para tiempo
    char sio;//respuesta corregida por sn()

    //Funciones
    void gui(const string& txt,int mseg){//muestra texto en pantalla por letra
        c=0;
        for(char c:txt){
            cout<<c<<flush;
            this_thread::sleep_for(chrono::milliseconds(mseg));
        }

    }
    void txt(const string& txt, int mseg){//texto por palabra
        istringstream stream(txt);
        string palabra;
        while(stream>>palabra){
            cout<<palabra<<" "<<flush;
            this_thread::sleep_for(chrono::milliseconds(mseg));
        }
    }
    void bag(){//muestra el contenido de la mochila
        string g14="Este es el contenido de la mochila:\n";
        gui(g14,V);
        for(int i=0;i<=3;i++){
            cout<<i+1<<"- ";
            txt(mochila[i],w);
            if(i<3){
                cout<<",\n";
            }else{
                cout<<".\n";
            }
        }
    }
    void res(){//permite el ingreso solo de caracteres numéricos
        do{
            //cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin>>respuesta;
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                string g0="Qué estas diciendo?? Deja de bromear.\n";
                gui(g0,v);
                bad=1;
            }else{bad=0;}
        }while(bad);
    }
    void hacer(){//compara texto ingresado con opciones correctas(correcto[])
        e=o=0;
        ok=0;
        do{ //clasificar elección
            for(int i=0;i<=objeto.size();i++){
                if(objeto[i]!=correcto[o][i]){
                    e++;
                }
            }
            if (e<=1){
                ok=1;
                bad=0;
            }else{
                bad=1;
                o++;
                e=0;
            }if(o>=4){
                bad=0;
            }
        }while(bad);
    }
    void tempo(int seg=1) {// temporizador para la respuesta
        while(!tiempo){
            this_thread::sleep_for(chrono::seconds(seg)); // Espera el tiempo indicado
            t++;
        }
    }
    void selec(){//permite limite de tiempo para ingresar respuesta
        t=0;
        thread time(tempo,seg);

        getline(cin,objeto);
        hacer();
        tiempo=true;
        time.detach();

        if (t>10){
            ok=false;
            string Tm="(¡Muy Tarde!)";
            cout<<endl;
            txt(Tm,w);
            cout<<"\n\n";
        }
    }
    void sn(){//permite la entrada de respuesta si/no y da un mensaje de error
        do{
            string yn="(si/no)";
            txt(yn,W);
            cout<<endl;
            //cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin>>sino;
            if(sino==r[0]||sino==r[1]||sino==r[2]){
                sio='s';
                bad=0;
            }else if(sino==r[3]||sino==r[4]||sino==r[5]){
                sio='n';
                bad=0;
            }else{
                string t7="<Tienes que decidir>";
                txt(t7,w);
                cout<<endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                bad=1;
            }
        }while(bad);

    }
    void usar(){//permite usar objetos disponibles en la mochila
        op[0]=op[1]=op[2]=op[3]=0;
        for(int i=0;i<=3;i++){
            objeto=mochila[i];
            //cout<<i<<endl;
            m=i;
            string u[9]={"algunos","algunas","alguna","algun","algún","unos","unas","una","un"};
            //            //objeto=mochila[m];
            do{// quitar unos
                size_t pos=objeto.find(u[c]);
                if(pos!=string::npos){
                    objeto.erase(pos,u[c].length());
                    if(objeto[pos]==' '){
                        objeto.erase(pos, 1);
                        bad=0;
                    }
                }else{
                    bad=1;
                    c++;
                }if(c==9){
                    bad=0;
                }
            }while(bad);


            do{ //clasificar objeto
                for(int i=0;i<=objeto.size();i++){
                    if(objeto[i]!=cosas[o][i]){
                        e++;
                        //cout<<cosas[o]<<o<<"\n"<<e<<endl;
                    }
                }
                //cout<<"aquí "<<e<<endl;

                if (e<=1){
                    string S[3]={"El objeto "," pertenece a ","\n\n"};
                    //gui(S[0]+cosas[o]+S[1]+tipos[obj[cosas[o]]]+S[2],V);
                    respuesta=obj[cosas[o]];
                    op[m]=1;
                    bad=0;
                }else{
                    bad=1;
                    o++;
                    e=0;
                }if(o>total){
                    //string N="El objeto es basura\n\n";
                    gui("",v);//no tocar, error al eliminar
                    e=0;
                    o=0;
                    bad=0;
                }
            }while(bad);
            if(tipos[respuesta]==correcto[0]){
                op[m]=1;
            }
            //cout<<m<<" "<<op[m]<<" "<<objeto<<endl;
        }
        if(op[0]==1||op[1]==1||op[2]==1||op[3]==1){
            string gU="Que objeto usarás?\n";
            gui(gU,V);
            txt("0-Ninguno",w);
            cout<<"\n";
            if(op[0]==1){
                txt("1-"+mochila[0],w);
                cout<<"\n";
            }if(op[1]==1){
                txt("2-"+mochila[1],w);
                cout<<"\n";
            }if(op[2]==1){
                txt("3-"+mochila[2],w);
                cout<<"\n";
            }if(op[3]==1){
                txt("4-"+mochila[3],w);
                cout<<"\n";
            }



            do{
                res();
                string tU=(ok&&respuesta!=0)?"(Usaste el objeto)":"(No usaste el objeto)";
                if((respuesta==1&&op[0]==1)||(respuesta==2&&op[1]==1)||(respuesta==3&&op[2]==1)||(respuesta==4&&op[3]==1)){
                    txt(tU,w);
                    cout<<"\n\n";
                    ok=1;
                    bad=0;
                }else if(respuesta==0){
                    ok=0;
                    txt(tU,w);
                    cout<<"\n\n";
                    txt(txx,w);
                    cout<<"\n\n";
                    bad=0;
                }else{
                    string gN="\nEsa no es una opción.\n";
                    gui(gN,V);
                    bad=1;
                }
            }while(bad);

        }else{
            gui(gxx,V);
            txt(txx,w);
            ok=0;
            //cout<<"\n\n"<<m<<op[0]<<op[1]<<op[2]<<op[3];
        }
    }

    //////////////GAME///////////////
    int main(int argc, char **argv) {
        ///*
        est["salud"]=est["sed"]=est["hambre"]=est["sueño"]=est["infección"]=100;
        mochila[0]=esp[0];
        mochila[1]=esp[1];
        mochila[2]=esp[2];
        mochila[3]=esp[3];

        //cout<<" "<<endl;
        string tI="\t\t<<<<<<<<Capitulo 1: Escape.>>>>>>>>\n\n\t\t..........mañana del día 0..........\n\n";
        gui(tI,V);
        string t0="";
        string g1="—Despierta!\n—Despierta!!\n—Noob!\tDespierta de una pv+@ vez!!!\n\n";
        string t1="Estas en el piso de una habitación oscura y llena de escombros\n";
        txt(t0,W);
        gui(g1,v);
        gui(t1+"\n",V);

        string despertando[5]={"Respuestas:","1-¿Qué pasó aquí?","2-¿Dónde estamos?","3-¿Quién eres?","4-Estoy listo"};

        //primera pregunta
        do{
            for(int i=0;i<=4;i++){
                txt(despertando[i],W);
                cout<<endl;
            }
            res();
            if(respuesta==1&&op[0]==0){
                string g2="\n—El helicóptero de rescate se estrelló, debiste perder la conciencia\n\n";
                gui(g2,v);
                despertando[1]="";
                op[0]=1;
            }else if(respuesta==2&&op[1]==0){
                string g3="\n—En el refugio, o... lo que queda de el...\n\n";
                gui(g3,v);
                despertando[2]="";
                op[1]=1;
            }else if(respuesta==3&&op[2]==0){
                string g4="\n—Eso no importa, mejor concentrémonos en salir de aquí rápido.\n\n";
                gui(g4,v);
                despertando[3]="";
                op[2]=1;
            }else if(respuesta==4){
                string g5="\n—Entonces muevete!\n\n";
                gui(g5,v);
            }else{
                string g6="\n—Qué dices?? No te entiendo. Debemos irnos de aquí ahora.\n\n";
                gui(g6,v);
            }
        }while(respuesta!=4);
        //mochila
        string g7="—¿Y bien a qué esperas? toma esto y lleva lo que necesites.\n\n";
        string t2="(Te ha dado una mochila)";
        string g8="\n\n—Noob! mira por la ventana y no hagas ruido.\n\n";
        string t3="A través del polvo y el humo vez las siluetas de personas que se acercan caminando de forma extraña al edificio. Parecen arrastrarse.";
        string g9="\n\n—Tenemos que irnos, toma tus cosas y sígueme.\n\n";
        string t4="(Has abierto tu mochila)";
        gui(g7,v);
        txt(t2,W);
        gui(g8,v);
        gui(t3,V);
        gui(g9,v);
        txt(t4,w);
        cout<<"\n\n";

        for(int i=0;i<=4;i++){
            if(i>0&&i<=3){
                string g10="Guardarás algo más?";
                gui(g10,V);
            }else if(i==0){
                string g11="Deseas guardar algo en la mochila?";
                gui(g11,V);
            }else{
                string t5="(Ya no hay espacio en la mochila)";
                txt(t5,w);
                cout<<"\n\n";
                break;
            }
            sn();
            if(sio=='s'){
                string g12="\nQué guardarás en la mochila?\n";
                gui(g12,V);
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin,mochila[i]);
                string g13="\nHas guardado ";
                string g14=" en tu mochila.\n\n";
                gui(g13,V);
                gui(mochila[i],V);
                gui(g14,V);
            }else if(sio=='n'){
                string t6="(Has cerrado la mochila)";
                txt(t6,W);
                cout<<"\n\n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
        }
        //ver mochila
        bag();

        string g15[2]={"\n—Mas te vale que hayas elegido bien.\n","\n—Salgamos de aquí.\n"};
        string t8="\nEscuchas un crujido proveniente del techo y algo de polvo cae de el.\n";
        string g16="\nEl sujeto que te despertó derribó la puerta de un empujón.\n";
        gui(g15[0],v);
        gui(t8,V);
        gui(g15[1],v);
        gui(g16,V);
        cout<<"\n\n";

        string g17="\nQué harás ahora??\n";
        //correcto[0,1,2,3]="salir","correr","seguirlo","ir con el"; NO FUNCIONO
        correcto[0]="salir";
        correcto[1]="correr";
        correcto[2]="seguirlo";
        correcto[3]="ir con el";
        gui(g17,V);

        selec();
        cout<<"(tardaste "<<t<<" segundos en responder)\n";

        string g18=(ok)?"\nSaliste por la puerta detrás del sujeto.\n\n<< Sobreviviste >>\n\n":"\nTan solo un segundo después el techo se derrumbo dejándote enterrado bajo los escombros.\n\n<<<< Has Muerto >>>>\n\n";//Syntax, menos lineas
        gui(g18,V);
        //*/

        //escape del refugio
        //ok=1;
        if(ok){
            string g19="Del otro lado de la puerta en el pasillo logras escuchar un enorme estruendo proveniente de la habitación en la que te encontrabas.\n\n";
            string g20="—Por poco y no la contamos, será mejor bucar una salida. Ve al final del pasillo, si trajiste alguna herramienta podríamos forzar la salida de emergencia, mientras tanto yo iré por provisiones.\n\n";
            string g21="Caminaste por el pasillo hasta la puerta de emergencia ignorando las demás.\nAbrirás la puerta??";

            gui(g19,V);
            gui(g20,v);
            gui(g21,V);

            //parametros de decision.
            correcto[0]=10;
            correcto[1]=15;
            gxx="\nEl marco de la puerta esta torcido, necesitas una herramienta para abrirla.\n";
            txx="(No abriste la puerta)";
            //mochila[3]="una escoba";
            sn();

            if(sio=='s'){
                usar();
            }else{
                ok=0;
                txt(txx,w);
                cout<<"\n\n";
            }


            //Salir
            string E=(ok)?"<<<<Saliste del edificio>>>>":"<<<<Quedaste atrapado>>>>";
            txt(E,W);
            cout<<"\n\n";

            bag();


            //Fin
        }else{

            string gF="\n\nFIN\n\n";
            gui(gF,w);
        }


        return 0;
    }
