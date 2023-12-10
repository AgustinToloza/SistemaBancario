#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Lista.h"
#include "Pila.h"
#include "Cola.h"
#include "Util.h"
#include "Cliente.h"
#include "Cuenta.h"
#include "Pago.h"
#include "Movimientos.h"

bool verificarIdCliente(PtrLista lista, int idCliente);
bool verificarIdCuenta(PtrLista lista, int idCuenta);
bool verificarIdClienteDeCuenta(PtrLista lista, int idClienteCuenta);
bool verificarIdClienteDeCuentaRepetido(PtrLista lista, int idClienteCuenta);
CuentaPtr getCuenta(PtrLista lista, int idCuenta);
ClientePtr getCliente(PtrLista lista, int idCliente);

int main()
{
    int opcion;
    int opcion2;
    int opcion3;
    int i = 0;
    int suma = 0;
    int resta = 0;
    bool encontrado = false;
    char c;

    // Variables temporales de cliente
    int idCliente;
    char nombre[20];
    char apellido[20];
    char ciudad[15];
    char direccion[15];
    int nDireccion;
    int edad;
    int telefono;
    char confirm[5];
    PtrLista listaClientes = crearLista();

    //Variables temporales de cuenta
    int idCuenta;
    int idClienteCuenta;
    char NIP[5];
    int nTipoCuenta;
    int saldo;
    int limiteCredito = 0;
    PtrLista listaCuentas = crearLista();
    PtrLista listaIdClientesCuentas = crearLista();

    //Variables temporales de movimientos
    char idTipoMov[3];
    char descripcion[50];
    int monto;
    char fecha[15];
    char empresa[20];

    //Variables aux
    int deposito = 0;
    int retiro = 0;
    int pago = 0;
    int idCuentaOrigen;
    int idCuentaDestino;
    int meses;
    int tasa;
    int resultado;
    int longitud;

    do{
        system("cls");

        printf("SISTEMA BANCARIO\n\n");
        printf("MENU PRINCIPAL\n\n");
        printf("1.Clientes\n");
        printf("2.Cuentas\n");
        printf("3.Depositos/Retiros\n");
        printf("4.Pago\n");
        printf("5.Transferencia\n");
        printf("6.Estado de cuenta\n");
        printf("7.Historial Movimientos\n");
        printf("8.Cola de Pagos\n");
        printf("9.Salir\n\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch(opcion){
            case 1:
                do{
                    system("cls");
                    printf("CLIENTES\n\n");
                    printf("1.Registro\n");
                    printf("2.Consulta\n");
                    printf("3.Regresar al menu principal\n\n");
                    printf("Ingrese una opcion: ");
                    scanf("%d", &opcion2);
                    system("cls");

                    switch(opcion2){
                        case 1:
                            printf("REGISTRO DE CLIENTE\n\n");
                            printf("Id Cliente: ");
                            scanf("%d", &idCliente);
                            while(verificarIdCliente(listaClientes,idCliente)==true || idCliente == 0){
                                printf("ID CLIENTE YA INGRESADO / 0 NO ES VALIDO / INGRESE OTRO: ");
                                scanf("%d", &idCliente);
                            }
                            printf("Nombre: ");
                            scanf("%s", nombre);
                            while ((c = getchar()) != '\n' && c != EOF) { };
                            /*fgets(nombres,30,stdin);
                            fflush(stdin);
                            longitud = strlen(nombres);
                            nombres[longitud-1] = '\0'; //Se remueve salto de linea de fgets / termina con \n \0 (DEBERIA FUNCIONAR PERO NO)*/
                            printf("Apellido: ");
                            scanf("%s", apellido);
                            while ((c = getchar()) != '\n' && c != EOF) { };
                            printf("Ciudad: ");
                            scanf("%s", ciudad);
                            while ((c = getchar()) != '\n' && c != EOF) { };
                            printf("Direccion (Calle): ");
                            scanf("%s", direccion);
                            while ((c = getchar()) != '\n' && c != EOF) { };
                            printf("Direccion (Numero): ");
                            scanf("%d", &nDireccion);
                            printf("Edad: ");
                            scanf("%d", &edad);
                            printf("Telefono: ");
                            scanf("%d", &telefono);
                            printf("\nConfirmar Registro de Cliente: Si[s] / No[n]: ");
                            scanf("%s", confirm);
                            if(strcmp(confirm,"s")==0){
                                ClientePtr c = crearCliente(idCliente,nombre,apellido,ciudad,direccion,nDireccion,edad,telefono);
                                agregarDatoLista(listaClientes,c);
                                printf("\nCliente Registrado Correctamente\n");
                                system("pause");
                            }else{
                                printf("\nNo se ha registrado el cliente\n");
                                system("pause");
                            }
                            break;
                        case 2:
                            printf("CONSULTA DE CLIENTES\n\n");
                            if(!listaVacia(listaClientes)){
                                printf("Ingrese Nombre del Cliente: ");
                                scanf("%s", nombre);
                                while ((c = getchar()) != '\n' && c != EOF) { };
                                printf("Ingrese Apellido del Cliente: ");
                                scanf("%s", apellido);
                                while ((c = getchar()) != '\n' && c != EOF) { };
                                system("cls");

                                ClientePtr c;
                                encontrado = false;
                                i = 0;

                                while(i<longitudLista(listaClientes) && encontrado == false){
                                    c = getDatoLista(listaClientes,i);
                                    if(strcmp(getNombre(c),nombre)==0 && strcmp(getApellido(c),apellido)==0){
                                        encontrado = true;
                                        printf("CONSULTA DE CLIENTES\n\n");
                                        printf("Id Cliente: %d\n", getIdCliente(c));
                                        printf("Nombre: %s %s\n", getNombre(c), getApellido(c));
                                        printf("Ciudad: %s\n", getCiudad(c));
                                        printf("Direccion: %s %d\n", getDireccion(c), getNdireccion(c));
                                        printf("Edad: %d\n", getEdad(c));
                                        printf("Telefono: %d\n\n", getTelefono(c));
                                        system("pause");
                                    }
                                    i++;
                                }
                                if(strcmp(getNombre(c),nombre)!=0 || strcmp(getApellido(c),apellido)!=0){
                                    printf("CONSULTA DE CLIENTES\n");
                                    printf("\nEl Nombre y/o Apellido Ingresado No es Valido\n");
                                    system("pause");
                                }
                            }else{
                                printf("No hay clientes registrados.\n");
                                system("pause");
                            }
                            break;
                    }
                }while(opcion2!=3);
                break;
            case 2:
                do{
                    system("cls");
                    printf("CUENTAS\n\n");
                    printf("1.Registro\n");
                    printf("2.Consultas\n");
                    printf("3.Regresar al menu principal\n\n");
                    printf("Ingrese una opcion: ");
                    scanf("%d", &opcion2);
                    system("cls");

                    switch(opcion2){
                        case 1:
                            printf("ALTA DE CUENTA\n\n");
                            if(!listaVacia(listaClientes)){
                                printf("Id Cuenta: ");
                                scanf("%d", &idCuenta);
                                while(verificarIdCuenta(listaCuentas,idCuenta)==true || idCuenta == 0){
                                    printf("ID CUENTA YA INGRESADO / 0 NO ES VALIDO / INGRESE OTRO: ");
                                    scanf("%d", &idCuenta);
                                }
                                printf("Id Cliente: ");
                                scanf("%d", &idClienteCuenta);
                                while(verificarIdClienteDeCuenta(listaClientes,idClienteCuenta)==false || verificarIdClienteDeCuentaRepetido(listaIdClientesCuentas,idClienteCuenta)==true){
                                    printf("(0 - SALIR) ID CLIENTE INVALIDO/USADO. INGRESE UN ID CLIENTE VALIDO: ");
                                    scanf("%d", &idClienteCuenta);
                                    if(idClienteCuenta==0){
                                        exit(1);
                                    }
                                }
                                printf("NIP: ");
                                scanf("%s", NIP);
                                while ((c = getchar()) != '\n' && c != EOF) { };
                                printf("N Tipo de Cuenta (1.Credito/2.Debito): ");
                                scanf("%d", &nTipoCuenta);
                                if(nTipoCuenta==1){
                                    limiteCredito = 30000;
                                }else if(nTipoCuenta==2){
                                    limiteCredito = 0;
                                }
                                printf("Saldo: $");
                                scanf("%d", &saldo);
                                if(nTipoCuenta == 1){
                                    while(saldo>30000){
                                        printf("EL SALDO INGRESADO SUPERA EL LIMITE DE 30000 (Cuenta de credito) / Ingrese otro: $");
                                        scanf("%d", &saldo);
                                    }
                                }
                                printf("\nConfirmar Registro de Cuenta: Si[s] / No[n]: ");
                                scanf("%s", confirm);
                                if(strcmp(confirm,"s")==0){
                                    PtrPila pilaMovimientos = crearPila();
                                    PtrCola colaPagos = crearCola();
                                    CuentaPtr c = crearCuenta(idCuenta,idClienteCuenta,NIP,nTipoCuenta,saldo,limiteCredito,pilaMovimientos,colaPagos);
                                    MovimientosPtr m = crearMovimientos(idCuenta,idClienteCuenta,"S","Saldo Inicial",saldo,"23/2/2023");
                                    apilar(getPilaMovimientos(c),m);
                                    agregarDatoLista(listaIdClientesCuentas,idClienteCuenta);
                                    agregarDatoLista(listaCuentas,c);
                                    printf("\nCuenta Registrada Correctamente\n");
                                    system("pause");
                                }else{
                                    printf("\nNo se ha registrado la cuenta\n");
                                    system("pause");
                                }
                            }else{
                                printf("No hay clientes registrados para permitir crear una cuenta.\n");
                                system("pause");
                            }
                            break;
                        case 2:
                            printf("CONSULTA DE CUENTAS\n\n");
                            if(!listaVacia(listaCuentas)){
                                printf("Ingrese ID de la Cuenta: ");
                                scanf("%d", &idCuenta);
                                system("cls");

                                CuentaPtr c;
                                encontrado = false;
                                i = 0;

                                while(i<longitudLista(listaCuentas) && encontrado == false){
                                    c = getDatoLista(listaCuentas,i);
                                    if(getIdCuenta(c) == idCuenta){
                                        encontrado = true;
                                        printf("CONSULTA DE CUENTAS\n\n");
                                        printf("Id Cuenta: %d\n", getIdCuenta(c));
                                        printf("Id Cliente: %d\n", getIdClienteCuenta(c));
                                        printf("NIP: %s\n", getNip(c));
                                        if(nTipoCuenta==1){
                                            printf("Tipo Cuenta: CREDITO\n");
                                        }else if(nTipoCuenta==2){
                                            printf("Tipo Cuenta: DEBITO\n");
                                        }
                                        printf("Saldo: $%d\n", getSaldo(c));
                                        if(nTipoCuenta==1){
                                            printf("Limite credito: $%d\n", getLimiteCredito(c));
                                        }
                                        printf("\n");
                                        system("pause");
                                    }
                                    i++;
                                }
                                if(getIdCuenta(c) != idCuenta){
                                    printf("CONSULTA DE CUENTAS\n");
                                    printf("\nID CUENTA INVALIDO\n");
                                    system("pause");
                                }
                            }else{
                                printf("No hay cuentas registradas.\n");
                                system("pause");
                            }
                            break;
                    }
                }while(opcion2!=3);
                break;
            case 3:
                do{
                    system("cls");
                    printf("DEPOSITO / RETIRO\n\n");
                    printf("1.Deposito\n");
                    printf("2.Retiro\n");
                    printf("3.Regresar al menu principal\n\n");
                    printf("Ingrese una opcion: ");
                    scanf("%d", &opcion2);
                    system("cls");

                    switch(opcion2){
                        case 1:
                            printf("DEPOSITO\n\n");
                            if(!listaVacia(listaCuentas)){
                                printf("Ingrese ID de Cuenta: ");
                                scanf("%d", &idCuenta);
                                if(verificarIdCuenta(listaCuentas,idCuenta)==true){
                                    CuentaPtr c = getCuenta(listaCuentas,idCuenta);
                                    if(getNtipoCuenta(c)==1){
                                        printf("Ingrese cantidad a depositar: $");
                                        scanf("%d", &deposito);
                                        suma = getSaldo(c) + deposito;
                                        if(suma<=30000){
                                            printf("\nConfirmar Transaccion: Si[s] / No[n]: ");
                                            scanf("%s", confirm);
                                            if(strcmp(confirm,"s")==0){
                                                setSaldo(c,suma);
                                                MovimientosPtr m = crearMovimientos(idCuenta,getIdClienteCuenta(c),"D","Deposito",deposito,"23/2/2023");
                                                apilar(getPilaMovimientos(c),m);
                                                printf("\nTransaccion realizada con exito.\n");
                                                system("pause");
                                            }else{
                                                printf("\nNo se ha realizado la transaccion\n");
                                                system("pause");
                                            }
                                        }else{
                                            printf("\nError! Valor limite superado.\n");
                                            system("pause");
                                        }
                                    }else if(c->nTipoCuenta==2){
                                        printf("Ingrese cantidad a depositar: $");
                                        scanf("%d", &deposito);
                                        suma = getSaldo(c) + deposito;
                                        printf("\nConfirmar Transaccion: Si[s] / No[n]: ");
                                        scanf("%s", confirm);
                                        if(strcmp(confirm,"s")==0){
                                            setSaldo(c,suma);
                                            MovimientosPtr m = crearMovimientos(idCuenta,getIdClienteCuenta(c),"D","Deposito",deposito,"23/2/2023");
                                            apilar(getPilaMovimientos(c),m);
                                            printf("\nTransaccion realizada con exito.\n");
                                            system("pause");
                                        }else{
                                            printf("\nNo se ha realizado la transaccion\n");
                                            system("pause");
                                        }
                                    }
                                }else{
                                    printf("\nID CUENTA INVALIDO\n");
                                    system("pause");
                                }
                            }else{
                                printf("No hay cuentas registradas.\n");
                                system("pause");
                            }
                            break;
                        case 2:
                            printf("RETIRO\n\n");
                            if(!listaVacia(listaCuentas)){
                                printf("Ingrese ID de Cuenta: ");
                                scanf("%d", &idCuenta);
                                if(verificarIdCuenta(listaCuentas,idCuenta)==true){
                                    CuentaPtr c = getCuenta(listaCuentas,idCuenta);
                                    printf("Ingrese NIP: ");
                                    scanf("%s", NIP);
                                    //while ((c = getchar()) != '\n' && c != EOF) { };
                                    if(strcmp(getNip(c),NIP)==0){
                                        printf("Ingrese cantidad a retirar: $");
                                        scanf("%d", &retiro);
                                        printf("\nConfirmar Transaccion: Si[s] / No[n]: ");
                                        scanf("%s", confirm);
                                        if(strcmp(confirm,"s")==0){
                                            if(getSaldo(c) >= retiro){
                                                resta = getSaldo(c) - retiro;
                                                setSaldo(c,resta);
                                                MovimientosPtr m = crearMovimientos(idCuenta,getIdClienteCuenta(c),"R","Retiro",retiro,"23/2/2023");
                                                apilar(getPilaMovimientos(c),m);
                                                printf("\nTransaccion realizada con exito.\n");
                                                system("pause");
                                            }else{
                                                printf("\nSaldo insuficiente para realizar la transaccion.\n");
                                                system("pause");
                                            }
                                        }else{
                                            printf("\nNo se ha realizado la transaccion.\n");
                                            system("pause");
                                        }
                                    }else{
                                        printf("\nNIP INVALIDO.\n");
                                        system("pause");
                                    }
                                }else{
                                    printf("\nID CUENTA INVALIDO.\n");
                                    system("pause");
                                }
                            }else{
                                printf("No hay cuentas registradas.\n");
                                system("pause");
                            }
                            break;
                    }
                }while(opcion2!=3);
                break;
            case 4:
                system("cls");
                printf("PAGO\n\n");
                if(!listaVacia(listaCuentas)){
                    printf("Ingrese ID Cuenta: ");
                    scanf("%d", &idCuenta);
                    if(verificarIdCuenta(listaCuentas,idCuenta)==true){
                        CuentaPtr c = getCuenta(listaCuentas,idCuenta);
                        printf("Ingrese NIP: ");
                        scanf("%s", NIP);
                        //while ((c = getchar()) != '\n' && c != EOF) { };
                        if(strcmp(getNip(c),NIP)==0){
                            if(getNtipoCuenta(c)==1){
                                printf("Ingrese cantidad a pagar: $");
                                scanf("%d", &pago);
                                printf("\nConfirmar Transaccion: Si[s] / No[n]: ");
                                scanf("%s", confirm);
                                if(strcmp(confirm,"s")==0){
                                    if(getSaldo(c) >= pago){
                                        PagoPtr p = crearPago(idCuenta,pago);
                                        encolar(getColaPagos(c),p);
                                        printf("\nPago agregado a la cola con exito.\n");
                                        system("pause");
                                    }else{
                                        printf("\nSaldo insuficiente para agregar el pago a la cola.\n");
                                        system("pause");
                                    }
                                }else{
                                    printf("\nNo se ha realizado la transaccion.\n");
                                    system("pause");
                                }
                            }else{
                                printf("\nERROR: LA CUENTA ES DE DEBITO / DEBE SER DE CREDITO.\n");
                                system("pause");
                            }
                        }else{
                            printf("\nNIP INVALIDO.\n");
                            system("pause");
                        }
                    }else{
                        printf("\nID CUENTA INVALIDO.\n");
                        system("pause");
                    }
                }else{
                    printf("No hay cuentas registradas.\n");
                    system("pause");
                }
                break;
            case 5:
                system("cls");
                printf("TRANSFERENCIA\n\n");
                if(!listaVacia(listaCuentas)){
                    printf("Ingrese ID Cuenta Origen: ");
                    scanf("%d", &idCuentaOrigen);
                    printf("Ingrese ID Cuenta Destino: ");
                    scanf("%d", &idCuentaDestino);
                    if(verificarIdCuenta(listaCuentas,idCuentaOrigen)==true && verificarIdCuenta(listaCuentas,idCuentaDestino)==true && idCuentaOrigen!=idCuentaDestino){
                        CuentaPtr cuentaOrigen = getCuenta(listaCuentas,idCuentaOrigen);
                        CuentaPtr cuentaDestino = getCuenta(listaCuentas,idCuentaDestino);
                        if(getNtipoCuenta(cuentaOrigen)==2 && getNtipoCuenta(cuentaDestino)==2){
                            printf("Ingrese NIP de la Cuenta Origen: ");
                            scanf("%s", NIP);
                            //while ((c = getchar()) != '\n' && c != EOF) { };
                            if(strcmp(getNip(cuentaOrigen),NIP)==0){
                                printf("//NIP VALIDO//\n");
                                printf("Ingrese cantidad a transferir: $");
                                scanf("%d", &pago);
                                printf("\nConfirmar Transaccion: Si[s] / No[n]: ");
                                scanf("%s", confirm);
                                if(strcmp(confirm,"s")==0){
                                    if(getSaldo(cuentaOrigen) >= pago){
                                        resta = getSaldo(cuentaOrigen) - pago;
                                        setSaldo(cuentaOrigen,resta);
                                        setSaldo(cuentaDestino,getSaldo(cuentaDestino)+pago);
                                        MovimientosPtr m1 = crearMovimientos(idCuentaOrigen,getIdClienteCuenta(cuentaOrigen),"T","Transf. Realizada",pago,"23/2/2023");
                                        apilar(getPilaMovimientos(cuentaOrigen),m1);
                                        MovimientosPtr m2 = crearMovimientos(idCuentaDestino,getIdClienteCuenta(cuentaDestino),"T+","Transf. Recibida",pago,"23/2/2023");
                                        apilar(getPilaMovimientos(cuentaDestino),m2);
                                        printf("\nTransaccion realizada con exito.\n");
                                        system("pause");
                                    }else{
                                        printf("\nSaldo insuficiente para realizar la transaccion.\n");
                                        system("pause");
                                    }
                                }else{
                                    printf("\nNo se ha realizado la transaccion.\n");
                                    system("pause");
                                }
                            }else{
                                printf("\nNIP INVALIDO.\n");
                                system("pause");
                            }
                        }else{
                            printf("\nCUENTA ORIGEN O DESTINO ES DE CREDITO / DEBE SER DE DEBITO.\n");
                            system("pause");
                            }
                    }else{
                        if(idCuentaOrigen==idCuentaDestino){
                            printf("\nERROR: ID CUENTA ORIGEN E ID CUENTA DESTINO SON IGUALES.\n");
                        }else{
                            printf("\nID CUENTA ORIGEN O DESTINO INVALIDO (NO EXISTE).\n");
                        }
                        system("pause");
                    }
                }else{
                    printf("No hay cuentas registradas.\n");
                    system("pause");
                }
                break;
            case 6:
                system("cls");
                printf("REPORTES\n\n");
                if(!listaVacia(listaCuentas)){
                    printf("Ingrese ID Cliente: ");
                    scanf("%d", &idCliente);
                    if(verificarIdCliente(listaClientes,idCliente)==true){
                        printf("Ingrese ID Cuenta: ");
                        scanf("%d", &idCuenta);
                        if(verificarIdCuenta(listaCuentas,idCuenta)==true){
                            CuentaPtr c = getCuenta(listaCuentas,idCuenta);
                            if(getIdClienteCuenta(c)==idCliente){
                                ClientePtr cl = getCliente(listaClientes,idCliente);
                                system("cls");
                                printf("ESTADO DE CUENTA\n\n");
                                printf("ID CLIENTE: %d\n",idCliente);
                                printf("NOMBRE CLIENTE: %s %s\n",getNombre(cl),getApellido(cl));
                                printf("CIUDAD: %s\n",getCiudad(cl));
                                printf("ID CUENTA: %d\n",idCuenta);
                                printf("SALDO ACTUAL: $%d\n\n",getSaldo(c));
                                printf("***MOVIMIENTOS***\n");
                                PtrPila pilaMovimientos = getPilaMovimientos(c);
                                for(int i=0;i<longitudPila(pilaMovimientos);i++){
                                    MovimientosPtr m = getDatoPila(pilaMovimientos,i);
                                    printf("FECHA MOV: %s --- TIPO MOVIMIENTO: %s --- CARGO: $%d\n",getFecha(m),getDescripcion(m),getMonto(m));
                                }
                                printf("\n");
                                system("pause");
                            }else{
                                printf("\nID CLIENTE INVALIDO PARA LA CUENTA INGRESADA.\n");
                                system("pause");
                            }
                        }else{
                            printf("\nID CUENTA INVALIDO.\n");
                            system("pause");
                        }
                    }else{
                        printf("\nID CLIENTE INVALIDO.\n");
                        system("pause");
                    }
                }else{
                    printf("No hay cuentas registradas.\n");
                    system("pause");
                }
                break;
            case 7:
                system("cls");
                printf("HISTORIAL MOVIMIENTOS\n\n");
                if(!listaVacia(listaCuentas)){
                    printf("Ingrese ID Cliente: ");
                    scanf("%d", &idCliente);
                    if(verificarIdCliente(listaClientes,idCliente)==true){
                        printf("Ingrese ID Cuenta: ");
                        scanf("%d", &idCuenta);
                        if(verificarIdCuenta(listaCuentas,idCuenta)==true){
                            CuentaPtr c = getCuenta(listaCuentas,idCuenta);
                            if(getIdClienteCuenta(c)==idCliente){
                                ClientePtr cl = getCliente(listaClientes,idCliente);
                                do{
                                    system("cls");
                                    printf("HISTORIAL MOVIMIENTOS\n\n");
                                    printf("ID CLIENTE: %d\n",idCliente);
                                    printf("ID CUENTA: %d\n",idCuenta);
                                    printf("NOMBRE CLIENTE: %s %s\n",getNombre(cl),getApellido(cl));
                                    printf("***MOVIMIENTOS***\n");
                                    PtrPila pilaMovimientos = getPilaMovimientos(c);
                                    for(int i=0;i<longitudPila(pilaMovimientos);i++){
                                        MovimientosPtr m = getDatoPila(pilaMovimientos,i);
                                        printf("FECHA MOV: %s --- TIPO MOVIMIENTO: %s --- CARGO: $%d\n",getFecha(m),getDescripcion(m),getMonto(m));
                                    }
                                    printf("\n");

                                    printf("1.Eliminar Ultimo Movimiento (desapilar)\n");
                                    printf("2.Regresar al menu principal\n\n");
                                    printf("Ingrese una opcion: ");
                                    scanf("%d", &opcion2);

                                    switch(opcion2){
                                        case 1:
                                            if(!pilaVacia(pilaMovimientos)){
                                                desapilar(pilaMovimientos);
                                                printf("\nULTIMO MOVIMIENTO ELIMINADO CON EXITO\n\n");
                                                system("pause");
                                            }else{
                                                printf("\nTODOS LOS MOVIMIENTOS YA HAN SIDO ELIMINADOS (desapilados)\n\n");
                                                system("pause");
                                            }
                                            break;
                                    }
                                }while(opcion2!=2);
                                system("cls");
                            }else{
                                printf("\nID CLIENTE INVALIDO PARA LA CUENTA INGRESADA.\n");
                                system("pause");
                            }
                        }else{
                            printf("\nID CUENTA INVALIDO.\n");
                            system("pause");
                        }
                    }else{
                        printf("\nID CLIENTE INVALIDO.\n");
                        system("pause");
                    }
                }else{
                    printf("No hay cuentas registradas.\n");
                    system("pause");
                }
                break;
            case 8:
                do{
                    system("cls");
                    printf("COLA DE PAGOS\n\n");
                    printf("1.Pagos Pendientes\n");
                    printf("2.Regresar al menu principal\n\n");
                    printf("Ingrese una opcion: ");
                    scanf("%d", &opcion2);
                    system("cls");

                    switch(opcion2){
                        case 1:
                            if(!listaVacia(listaCuentas)){
                                printf("COLA DE PAGOS\n\n");
                                printf("Ingrese ID Cuenta: ");
                                scanf("%d", &idCuenta);
                                if(verificarIdCuenta(listaCuentas,idCuenta)==true){
                                    CuentaPtr c = getCuenta(listaCuentas,idCuenta);
                                    PtrCola colaPagos = getColaPagos(c);
                                    if(!colaVacia(colaPagos)){
                                        do{
                                            system("cls");
                                            printf("COLA DE PAGOS\n\n");
                                            printf("ID CUENTA: %d\n",idCuenta);
                                            printf("***COLA DE PAGOS PENDIENTES***\n");
                                            for(int i=0;i<longitudCola(colaPagos);i++){
                                                PagoPtr pago = getDatoCola(colaPagos,i);
                                                printf("TIPO MOVIMIENTO: PAGO --- CARGO: $%d\n",getMontoPago(pago));
                                            }
                                            printf("\n");

                                            printf("1.Realizar Pago(desencolar)\n");
                                            printf("2.Regresar al menu principal\n\n");
                                            printf("Ingrese una opcion: ");
                                            scanf("%d", &opcion3);
                                            switch(opcion3){
                                                case 1:
                                                    if(!colaVacia(colaPagos)){
                                                        PagoPtr pago = primeroCola(colaPagos);
                                                        if(getSaldo(c) >= getMontoPago(pago)){
                                                            setSaldo(c, getSaldo(c) - getMontoPago(pago));
                                                            MovimientosPtr m = crearMovimientos(idCuenta,getIdClienteCuenta(c),"P","Pago",getMontoPago(pago),"22/5/2023");
                                                            apilar(getPilaMovimientos(c),m);

                                                            desencolar(colaPagos);
                                                            printf("PAGO REALIZADO CON EXITO\n\n");
                                                            system("pause");
                                                        }else{
                                                            printf("\nSaldo insuficiente para realizar el pago.\n");
                                                            system("pause");
                                                        }
                                                    }else{
                                                        printf("NO HAY PAGOS RESTANTES (desencolados)\n\n");
                                                        system("pause");
                                                    }
                                                    break;
                                                }
                                        }while(opcion3!=2);
                                    }else{
                                        printf("\nNO HAY PAGOS PENDIENTES EN LA COLA.\n");
                                        system("pause");
                                    }
                                }else{
                                    printf("\nID CUENTA INVALIDO.\n");
                                    system("pause");
                                }
                            }else{
                                printf("No hay cuentas registradas.\n");
                                system("pause");
                            }
                        break;
                    }
                }while(opcion2!=2);

            break;
        }
    }while(opcion!=9);

    return 0;
}

bool verificarIdCliente(PtrLista lista, int idCliente){
    bool esIgual = false;
    for(int i=0;i<longitudLista(lista);i++){
        ClientePtr c = getDatoLista(lista,i);
        if(c->idCliente==idCliente){
            esIgual = true;
        }
    }
    return esIgual;
}

bool verificarIdCuenta(PtrLista lista, int idCuenta){
    bool esIgual = false;
    for(int i=0;i<longitudLista(lista);i++){
        CuentaPtr c = getDatoLista(lista,i);
        if(c->idCuenta==idCuenta){
            esIgual = true;
        }
    }
    return esIgual;
}

bool verificarIdClienteDeCuenta(PtrLista lista, int idClienteCuenta){
    bool esIgual = false;
    for(int i=0;i<longitudLista(lista);i++){
        ClientePtr c = getDatoLista(lista,i);
        if(c->idCliente==idClienteCuenta){
            esIgual = true;
        }
    }
    return esIgual;
}

bool verificarIdClienteDeCuentaRepetido(PtrLista lista, int idClienteCuenta){
    bool esIgual = false;
    for(int i=0;i<longitudLista(lista);i++){
        int id = getDatoLista(lista,i);
        if(id==idClienteCuenta){
            esIgual = true;
        }
    }
    return esIgual;
}

CuentaPtr getCuenta(PtrLista lista, int idCuenta){
    for(int i=0;i<longitudLista(lista);i++){
        CuentaPtr c = getDatoLista(lista,i);
        if(c->idCuenta==idCuenta){
            return c;
        }
    }
    return NULL;
}

ClientePtr getCliente(PtrLista lista, int idCliente){
    for(int i=0;i<longitudLista(lista);i++){
        ClientePtr c = getDatoLista(lista,i);
        if(c->idCliente==idCliente){
            return c;
        }
    }
    return NULL;
}

