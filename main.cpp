#include <iostream>
#include <string>
#include "misfunciones.h"
using namespace std;

/// main

int main()
{
    int codMarca[10] = {0};
    string nombreMarca[10];
    int codProductos[20] = {0};
    string nombreProducto[20];
    float precioProducto[20] = {0};
    string codFormaPago[5];
    string nombreFormaPago[5];
    int porcentaje[5];
    float totalRecaudadoPorProducto[20] = {0};
    int cantidadVendidaPorProducto[20] = {0};



    int opcion;
    do
    {
        cout << "\n====================================" << endl;
        cout << " GESTION DE COMERCIO" << endl;
        cout << "====================================" << endl;
        cout << "1 - Cargar lote de marcas" << endl;
        cout << "2 - Cargar lote de productos" << endl;
        cout << "3 - Cargar lote de formas de pago" << endl;
        cout << "4 - Cargar lote de ventas" << endl;
        cout << "5 - Mostrar reportes" << endl;
        cout << "0 - Salir" << endl;
        cout << "====================================" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch(opcion)
        {
        case 1:
            cargarMarcas(codMarca, nombreMarca);
            break;
        case 2:
               cargarProductos(codMarca,
                              codProductos,
                              nombreProducto,
                              precioProducto);
            break;
        case 3:
            cargarFormasPago(codFormaPago, nombreFormaPago, porcentaje);
            break;
        case 4:
            cargarVentas(codProductos, precioProducto,nombreProducto,
                 totalRecaudadoPorProducto, cantidadVendidaPorProducto);
            break;
        case 5:
            menuReportes();
            break;
        case 0:
            cout << "\nPrograma finalizado." << endl;
            break;
        default:
            cout << "\nOpcion invalida." << endl;
        }
    }
    while(opcion != 0);
    return 0;
}
