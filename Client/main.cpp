
//Creado por Bradly Valverde F.
//Referencia utilizada para la creacion del cliente: https://www.geeksforgeeks.org/socket-programming-cc/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

#include "MPointer.h"
#include "LinkedList.h"
#include "DoubleNode.h"
#include "DoubleLinkedList.h"

#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"

#include "MPointer_init.h"

#include <string>

using namespace rapidjson;

using namespace std;

#include <arpa/inet.h>
#define PORT 8000//puerto a conectar


MPointer<int> list[5];//Lista que almacena los MPointers creados
int ubicacion = 0;// Variable para guardar los MPointers en su lugar correspondiente

int main() {

    cout << "Inicializando MPointer_init" << endl;

    MPointer_init initial(PORT);

    MPointer<int> ptr; //el MPointer creado para almacenarse si así se desea
    ptr = MPointer<int>::New();


    struct sockaddr_in address;//Direccion a la que se conecta el cliente
    int sock = 0, valread; //socket y variable para leer el mensaje del servidor
    struct sockaddr_in serv_addr;//Direccion en la que está el servidor

    //Metodo para crear el socket y su descriptor y metodo para verificar que se cree correctamente
    //Se utiliza para acceder a recursos de entrada y salida de un sistemas
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }
    //Pone el primer numero de bytes de memoria por el puntero a un valor especifico
    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;//Dice de que tipo sera el direccion
    serv_addr.sin_port = htons(initial.port);//Pasa el puerto en el que se encuentra el servidor

    // convierte las direcciones de IPv4 y IPv6 de texto a forma binaria
    if (inet_pton(AF_INET, initial.address, &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    //Conecta al socket refenciando por el descriptor sockfd a una direccion especificada
    if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }


    int decision = 0;// variable para saber ver que quiere hacer el cliente


    char buffer[1024];// buffer que almacenará el mensaje proveniente del servidor


    cout << "¿Que desea hacer?" << endl;
    cout << "1: Crear un MPointer" << endl;
    cout << "2: Cambiar el valor de algun MPointer guardado en el servidor" << endl;
    cout << "3: Mostrar todos los valores de los MPointer almacenados en el servidor" << endl;
    cout << "4: Ver memoria restante" << endl;
    cout << "5: Ver los pointer almacenados" << endl;
    cout << "6: Cerrar conexion" << endl;
    cin >> decision;

    //Crea un nuevo pointer y almacena sus datos
    if (decision == 1) {

        //JSON
        const char *json = "{\"code\": 1 ,\n"
                           "    \"valores\": \"nada\",\n"
                           "    \"id\": 0,\n"
                           "    \"memoria\": 0,\n"
                           "    \"valor\": 0}";

        send(sock, json, strlen(json), 0);//Envia el socket a el servidor

        printf("Se envio una solicitud de memoria\n");

        valread = read(sock, buffer, 1024);//lee el mensaje del servidor y lo almacena en el buffer


        Document JSON;//Crea un documento JSON del header RAPIDJson
        JSON.Parse(buffer);//Parsea el JSON

        assert(JSON["memoria"].IsNumber());//Confirma si la referencia del JSON el es valor esperado

        assert(JSON["memoria"].IsInt());

        if (JSON["memoria"].GetInt() != 0) {//obtiene su valor su el assert fue correcto
            assert(JSON["id"].IsNumber());

            assert(JSON["id"].IsInt());


            ptr.setID(JSON["id"].GetInt());


            int valor;

            cout << "¿Que valor desea ponerle a su MPointer?" << endl;
            cin >> valor;

            *ptr = valor;

            list[ubicacion] = *ptr;
            ubicacion++;


            Value &node = JSON["valor"];//Se crea un nodo para poder cambiarle el valor al el string referenciado
            node.SetInt(valor);//Cambia su valor con el metodo SetInt(int i)

            StringBuffer newJson;//Se crea un buffer
            Writer<StringBuffer> writer(newJson);//se crea writer para sobre escribir el ese buffer
            JSON.Accept(writer);//el JSON acepta el writer y sobreescribe lo que hay en su documento al buffer




//                cout << "Valor del pointer con el ID: "<< 0 << " es " << *list[0] << endl;
//                cout << "Valor del pointer con el ID: "<< 1 << " es " << *list[1] << endl;
//                cout << "Valor del pointer con el ID: "<< 2 << " es " << *list[2] << endl;
//                cout << "Valor del pointer con el ID: "<< 3 << " es " << *list[3] << endl;
//                cout << "Valor del pointer con el ID: "<< 4 << " es " << *list[4] << endl;


            send(sock, newJson.GetString(), strlen(json), 0);//envia el socket
        } else {
            cout << "No se pueden almacenar mas datos" << endl;
        }
        //Con el id se busca el Mpointer y se cambian sus datos tanto en el cliente como el servidor
    } else if (decision == 2) {
        const char *json = "{\"code\": 2 ,\n"
                           "    \"valores\": \"nada\",\n"
                           "    \"id\": 0,\n"
                           "    \"memoria\": 0,\n"
                           "    \"valor\": 0}";


        int valorID;

        int valorInt;

        cout << "Digite el ID del MPointer que desea cambiar " << endl;
        cin >> valorID;

        cout << "Digite el valor por el que desea cambiar " << endl;
        cin >> valorInt;

        *list[valorID] = valorInt;//Se obtiene la referencia del MPointer y se cambia su valor

        Document JSON;
        JSON.Parse(json);

        Value &nodeID = JSON["id"];
        nodeID.SetInt(valorID);

        Value &nodeValor = JSON["valor"];
        nodeValor.SetInt(valorInt);

        StringBuffer newJson;
        Writer<StringBuffer> writer(newJson);
        JSON.Accept(writer);


        send(sock, newJson.GetString(), strlen(newJson.GetString()), 0);

        //Se imprimen los valores en memoria en la terminal del servidor
    } else if (decision == 3) {
        const char *json = "{\"code\": 3 ,\n"
                           "    \"valores\": \"nada\",\n"
                           "    \"id\": 0,\n"
                           "    \"memoria\": 0,\n"
                           "    \"valor\": 0}";
        send(sock, json, strlen(json), 0);

        printf("Se envio una solicitud para recibir valores en memoria del servidor\n");

        //Se pide la memoria restante que hay en el servidor a manera de bytes
    } else if (decision == 4) {
        const char *json = "{\"code\": 4 ,\n"
                           "    \"valores\": \"nada\",\n"
                           "    \"id\": 0,\n"
                           "    \"memoria\": 0,\n"
                           "    \"valor\": 0}";

        send(sock, json, strlen(json), 0);

        printf("Se envio una solicitud para recibir la memoria restante\n");

        valread = read(sock, buffer, 1024);

        Document JSON;
        JSON.Parse(buffer);

        assert(JSON["memoria"].IsNumber());

        assert(JSON["memoria"].IsInt());

        printf("memoria restante = %d\n", JSON["memoria"].GetInt());

        //Imprime los valores de los Mpointers almacenados con su respectivo id
    } else if (decision == 5) {


        for (int i = 0; i < 5; i++) {
            cout << "Valor del pointer con el ID: " << i << " es " << *list[i] << endl;
        }
        //Decision para cerrar la conexion
    }else if (decision == 6){
        const char *json = "{\"code\": 4 ,\n"
                           "    \"valores\": \"nada\",\n"
                           "    \"id\": 0,\n"
                           "    \"memoria\": 0,\n"
                           "    \"valor\": 0}";

        send(sock, json, strlen(json), 0);
        printf("Se cerrará la conexion\n");
        return 0;
    }

    main();


}



