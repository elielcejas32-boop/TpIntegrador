#include <iostream>
#include "misfunciones.h"
using namespace std;
///misfunciones.cpp


void cargarMarcas(int codMarca[], string nombreMarca[])
{
    const int TAM = 10;

    for(int i = 0; i < TAM; i++)
    {
        do
        {
            cout << "\nIngrese el codigo de la marca: ";
            cin >> codMarca[i];

            if(codMarca[i] < 1 || codMarca[i] > 10)
            {
                cout << "Error. El codigo debe estar entre 1 y 10." << endl;
            }

        }
        while(codMarca[i] < 1 || codMarca[i] > 10);

        cout << "Ingrese el nombre de la marca: ";
        cin >> nombreMarca[i];

    }
    cout << "\nLote de marcas cargado correctamente." << endl;
}
void cargarProductos(int codMarca[],
                     int codProductos[],
                     string nombreProducto[],
                     float precioProducto[])
{
    if(codMarca[0] == 0 && codMarca[1] == 0 && codMarca[9] == 0)
    {
        cout << "\nError. No se cargaron las marcas previamente." << endl;
        return;
    }

    const int TAMPROD = 20;

    float precioCompra[TAMPROD];
    int stockDisponible[TAMPROD];
    int CodMarca[TAMPROD];

    for(int j = 0; j < TAMPROD; j++)
    {
        cout << "\nIngrese el codigo del producto:" << endl;
        cin >> codProductos[j];

        if(codProductos[j] == 0)
        {
            cout << "\nError codigo del producto vacio. Carga interrumpida." << endl;
            codProductos[0] = 0;
            return;
        }

        cout << "Ingrese el nombre del producto:" << endl;
        cin >> nombreProducto[j];

        if(nombreProducto[j] == "")
        {
            cout << "\nError nombre vacio. Carga interrumpida." << endl;
            codProductos[0] = 0;
            return;
        }

        cout << "\nIngrese el precio de venta:" << endl;
        cin >> precioProducto[j];

        if(precioProducto[j] == 0)
        {
            cout << "\nError precio de venta vacio. Carga interrumpida." << endl;
            codProductos[0] = 0;
            return;
        }

        cout << "\nIngrese el precio de compra:" << endl;
        cin >> precioCompra[j];

        if(precioCompra[j] == 0)
        {
            cout << "\nError el precio de compra esta vacio. Carga interrumpida." << endl;
            codProductos[0] = 0;
            return;
        }

        cout << "\nIngrese el stock disponible:" << endl;
        cin >> stockDisponible[j];

        if(stockDisponible[j] == 0)
        {
            cout << "\nError el stock disponible esta vacio. Carga interrumpida." << endl;
            codProductos[0] = 0;
            return;
        }

        cout << "\nIngrese el codigo de marca:" << endl;
        cin >> CodMarca[j];

        if(CodMarca[j] == 0)
        {
            cout << "\nError codigo de marca vacio. Carga interrumpida." << endl;
            codProductos[0] = 0;
            return;
        }

        int posMarca = CodMarca[j] - 1;

        if(CodMarca[j] < 1 || CodMarca[j] > 10 || codMarca[posMarca] == 0)
        {
            cout << "\nCodigo de marca no encontrado en el lote de marcas." << endl;
            codProductos[0] = 0;
            return;
        }
    }

    cout << "\nLote de productos cargado correctamente." << endl;
}

void cargarFormasPago(string codFormaPago[],
                      string nombreFormaPago[],
                      int porcentaje[])
{
    const int TAM = 5;

    for(int i = 0; i < TAM; i++)
    {
        cout << "\nIngrese el codigo de la forma de pago (EF, MP, TR, TC, CT): ";
        cin >> codFormaPago[i];

        if(codFormaPago[i] != "EF" &&
                codFormaPago[i] != "MP" &&
                codFormaPago[i] != "TR" &&
                codFormaPago[i] != "TC" &&
                codFormaPago[i] != "CT")
        {
            cout << "\nError. Codigo de forma de pago invalido. Carga interrumpida." << endl;
            codFormaPago[0] = "";
            return;
        }

        for(int j = 0; j < i; j++)
        {
            if(codFormaPago[i] == codFormaPago[j])
            {
                cout << "\nError. Codigo de forma de pago repetido. Carga interrumpida." << endl;
                codFormaPago[0] = "";
                return;
            }
        }

        cin.ignore();

        cout << "Ingrese el nombre de la forma de pago: ";
        getline(cin, nombreFormaPago[i]);

        if(nombreFormaPago[i] == "")
        {
            cout << "\nError. Nombre vacio. Carga interrumpida." << endl;
            codFormaPago[0] = "";
            return;
        }

        cout << "Ingrese el porcentaje de descuento o interes: ";
        cin >> porcentaje[i];
    }

    cout << "\nLote de formas de pago cargado correctamente." << endl;
}

void cargarVentas(int codigosProductos[], float preciosProductos[], string nombresProductos[],
                  float totalRecaudadoPorProducto[], int cantidadVendidaPorProducto[])
{
    int nroCompra;
    int codProd;
    string formaPago;
    int cantVendida;
    int codCliente;
    int diaVenta;

    cout << "\nIngrese el numero de compra:" << endl;
    cin>>nroCompra;

    while (nroCompra != 0)
    {
        cout << "\nIngrese el codigo de producto:" << endl;
        cin>>codProd;

        int indice = -1;
        for(int i = 0; i < 20; i++)
        {
            if(codigosProductos[i] == codProd)
            {
                indice = i;
                break;
            }
        }

        cout << "\nIngrese la forma de pago:" << endl;
        cin>>formaPago;

        if(indice != -1)
        {
            cout << "Ingrese la cantidad vendida: ";
            cin >> cantVendida;
            totalRecaudadoPorProducto[indice] += (preciosProductos[indice] * cantVendida);
            cantidadVendidaPorProducto[indice] += cantVendida;
            cout << "Venta registrada para: " << nombresProductos[indice] << endl;
        }
        else
        {
            cout << "Error: Codigo de producto no encontrado." << endl;
        }

        cout << "\nIngrese el codigo de cliente:" << endl;
        cin>>codCliente;

        cout << "\nIngrese el dia de venta:" << endl;
        cin>>diaVenta;


        cout << "\nIngrese el siguiente numero de compra (0 para terminar): ";
        cin >> nroCompra;
    }
    cout << "\nFin de carga de venta." << endl;
}

void menuReportes()
{
    int opcionReporte;
    do
    {
        cout << "\n========== REPORTES ==========" << endl;
        cout << "1 - Recaudacion por producto" << endl;
        cout << "2 - Ventas por forma de pago" << endl;
        cout << "3 - Ventas por marca y forma de pago" << endl;
        cout << "4 - Productos sin ventas" << endl;
        cout << "5 - Top 10 clientes + sorteo" << endl;
        cout << "0 - Volver al menu principal" << endl;
        cout << "Opcion: ";
        cin >> opcionReporte;

        switch(opcionReporte)
        {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        default:
            cout << "\nOpcion invalida." << endl;
        }
    }
    while(opcionReporte != 0);
}
