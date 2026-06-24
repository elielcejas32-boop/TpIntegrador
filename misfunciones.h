#ifndef MISFUNCIONES_H_INCLUDED
#define MISFUNCIONES_H_INCLUDED
#include <iostream>
#include <string>
///funcion.h

using namespace std;

void cargarMarcas(int codMarca[], string nombreMarca[]);
void cargarProductos(int codMarca[],int codProductos[],
string nombreProducto[],float precioProducto[]);
void cargarFormasPago
(string codFormaPago[],string nombreFormaPago[],int porcentaje[]);
void cargarVentas(int codigosProductos[], float preciosProductos[], string nombresProductos[],
                  float totalRecaudadoPorProducto[], int cantidadVendidaPorProducto[]);

void menuReportes();
void mostrarReporteRecaudacion(int codigos[], string nombres[], float recaudado[], int cantidades[], int stock[]);


#endif // MISFUNCIONES_H_INCLUDED
