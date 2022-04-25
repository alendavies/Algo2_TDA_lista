#include "src/lista.h"
#include "src/pila.h"
#include "src/cola.h"
#include <stdio.h>
#include <stdlib.h>
#include "pa2m.h"

void creo_una_pila_y_devuelve_una_pila_vacia_con_tope_nulo()
{
	pila_t *pila = pila_crear();

	pa2m_afirmar(pila != NULL, "La pila creada es válida");
	pa2m_afirmar(pila_tamanio(pila) == 0 && pila_vacia(pila), "La pila creada está vacía");
	pa2m_afirmar(pila_tope(pila) == NULL, "La pila creada tiene tope nulo");

	pila_destruir(pila);
}

void apilo_un_elemento_y_se_incrementa_el_tamanio_de_la_pila()
{
	pila_t *pila = pila_crear();
	int elemento1 = 5;
	int elemento2 = 7;

	pa2m_afirmar(pila_apilar(pila, &elemento1) == pila, "Puedo apilar un elemento y se devuelve la pila");
	pa2m_afirmar(pila_tamanio(pila) == 1 && !pila_vacia(pila), "Al apilar un elemento el tamaño de la pila es 1");
	pa2m_afirmar(pila_tope(pila) == &elemento1, "El tope de la pila es el correcto");

	pa2m_afirmar(pila_apilar(pila, &elemento2) == pila, "Puedo apilar un segundo elemento y se devuelve la pila");
	pa2m_afirmar(pila_tamanio(pila) == 2 && !pila_vacia(pila), "Al apilar otro elemento el tamaño de la pila es 2");
	pa2m_afirmar(pila_tope(pila) == &elemento2, "El tope de la pila es el correcto");

	pila_destruir(pila);
}

void puedo_apilar_un_elemento_NULL()
{
	pila_t *pila = pila_crear();

	pa2m_afirmar(pila_apilar(pila, NULL) == pila, "Puedo apilar un elemento NULL");
	pa2m_afirmar(pila_tamanio(pila) == 1 && !pila_vacia(pila), "Al apilar un elemento NULL el tamaño de la pila es 1");
	pa2m_afirmar(pila_tope(pila) == NULL, "El tope de la pila es NULL");

	pila_destruir(pila);
}

void no_se_puede_apilar_en_una_pila_nula()
{
	int elemento = 8;
	pa2m_afirmar(pila_apilar(NULL, &elemento) == NULL, "No puedo apilar en una pila nula");
}

void no_se_puede_desapilar_en_una_pila_nula()
{
	pa2m_afirmar(pila_desapilar(NULL) == NULL, "No puedo desapilar en una pila nula");
}

void desapilo_un_elemento_y_disminuye_el_tamanio_de_la_pila()
{
	pila_t *pila = pila_crear();
	int elemento1 = 5;
	int elemento2 = 7;
	int elemento3 = 10;

	pila_apilar(pila, &elemento1);
	pila_apilar(pila, &elemento2);
	pila_apilar(pila, &elemento3);

	pa2m_afirmar(pila_desapilar(pila) == &elemento3, "Puedo desapilar un elemento y devuelve el elemento desapilado");
	pa2m_afirmar(pila_tamanio(pila) == 2 && !pila_vacia(pila), "Al desapilar un elemento en una pila con 3 elementos, el tamaño de la pila es 2");
	pa2m_afirmar(pila_tope(pila) == &elemento2, "El tope de la pila es el correcto");

	pa2m_afirmar(pila_desapilar(pila) == &elemento2, "Puedo desapilar un segundo elemento y devuelve el elemento desapilado");
	pa2m_afirmar(pila_tamanio(pila) == 1 && !pila_vacia(pila), "Al desapilar un elemento en una pila con 2 elementos, el tamaño de la pila es 1");
	pa2m_afirmar(pila_tope(pila) == &elemento1, "El tope de la pila es el correcto");

	pa2m_afirmar(pila_desapilar(pila) == &elemento1, "Puedo desapilar un tercer elemento y devuelve el elemento desapilado");
	pa2m_afirmar(pila_tamanio(pila) == 0 && pila_vacia(pila), "Al desapilar un tercer elemento en una pila con 1 elemento, el tamaño de la pila es 0");
	pa2m_afirmar(pila_tope(pila) == NULL, "El tope de la pila es el correcto");

	pila_destruir(pila);
}

void creo_una_cola_y_devuelve_una_cola_vacia_con_frente_nulo()
{
	cola_t *cola = cola_crear();

	pa2m_afirmar(cola != NULL, "La cola creada es válida");
	pa2m_afirmar(cola_tamanio(cola) == 0 && cola_vacia(cola), "La cola creada es de tamaño 0");
	pa2m_afirmar(cola_frente(cola) == NULL, "El elemento en el frente de la cola es nulo");

	cola_destruir(cola);
}

void creo_una_lista_y_me_devuelve_una_lista_vacía_con_principio_y_fin_nulos()
{
	lista_t *lista = lista_crear();

	pa2m_afirmar(lista != NULL, "La lista creada es válida");
	pa2m_afirmar(lista_tamanio(lista) == 0 && lista_vacia(lista), "La lista creada es de tamaño 0");
	pa2m_afirmar(lista_ultimo(lista) == NULL, "El último elemento de la lista es nulo");
	pa2m_afirmar(lista_primero(lista) == NULL, "El primer elemento de la lista es nulo");

	lista_destruir(lista);
}

void no_se_puede_insertar_en_una_lista_nula()
{
	char elemento = 'a';
	pa2m_afirmar(lista_insertar(NULL, &elemento) == NULL && lista_insertar_en_posicion(NULL, &elemento, 2) == NULL, "No puedo insertar en una lista nula");
}

void inserto_un_elemento_al_final_y_se_incrementa_el_tamanio_de_la_lista()
{
	lista_t *lista = lista_crear();

	char elemento1 = 'a';
	char elemento2 = 'b';

	pa2m_afirmar(lista_insertar(lista, &elemento1) == lista, "Puedo insertar un elemento al final de una lista vacía");
	pa2m_afirmar(lista_tamanio(lista) == 1 && !lista_vacia(lista), "Al insertar un elemento en una lista vacía el tamaño de la lista es 1");
	pa2m_afirmar(lista_ultimo(lista) == &elemento1 && lista_primero(lista) == &elemento1, "El último de la lista y el primero son el mismo elemento");

	pa2m_afirmar(lista_insertar(lista, &elemento2) == lista, "Puedo insertar un elemento al final de una lista con elementos");
	pa2m_afirmar(lista_tamanio(lista) == 2 && !lista_vacia(lista), "Al insertar un elemento al final de una lista el tamaño de la lista aumenta");
	pa2m_afirmar(lista_ultimo(lista) == &elemento2 && lista_primero(lista) == &elemento1, "El último de la lista y el primero son los correctos");

	lista_destruir(lista);
}

void inserto_un_elemento_y_se_incrementa_el_tamanio_de_la_lista()
{
	lista_t *lista = lista_crear();

	char elemento3 = 'c';
	char elemento4 = 'd';
	char elemento5 = 'e';
	char elemento6 = 'f';
	char elemento7 = 'g';
	
	pa2m_afirmar(lista_insertar_en_posicion(lista, &elemento6, 0) == lista, "Puedo insertar un elemento una lista vacia");
	pa2m_afirmar(lista_tamanio(lista) == 1 && !lista_vacia(lista), "Al insertar un elemento a el tamaño de la lista aumenta");
	pa2m_afirmar(lista_elemento_en_posicion(lista, 0) == &elemento6, "El elemento en la posicion es el insertado");
	pa2m_afirmar(lista_ultimo(lista) == &elemento6 && lista_primero(lista) == &elemento6, "El último de la lista y el primero son los correctos");

	pa2m_afirmar(lista_insertar_en_posicion(lista, &elemento3, 1) == lista, "Puedo insertar un elemento en una lista con elementos");
	pa2m_afirmar(lista_tamanio(lista) == 2 && !lista_vacia(lista), "Al insertar un elemento en una lista el tamaño de la lista aumenta");
	pa2m_afirmar(lista_elemento_en_posicion(lista, 1) == &elemento3, "El elemento en la posicion es el insertado");
	pa2m_afirmar(lista_ultimo(lista) == &elemento3 && lista_primero(lista) == &elemento6, "El último de la lista y el primero son los correctos");

	pa2m_afirmar(lista_insertar_en_posicion(lista, &elemento5, 2) == lista, "Puedo insertar otro elemento en una lista con elementos");
	pa2m_afirmar(lista_tamanio(lista) == 3 && !lista_vacia(lista), "Al insertar un elemento en el medio de una lista el tamaño de la lista aumenta");
	pa2m_afirmar(lista_elemento_en_posicion(lista, 2) == &elemento5, "El elemento en la posicion es el insertado");
	pa2m_afirmar(lista_ultimo(lista) == &elemento5 && lista_primero(lista) == &elemento6, "El último de la lista y el primero son los correctos");

	pa2m_afirmar(lista_insertar_en_posicion(lista, &elemento4, 3) == lista, "Puedo insertar un elemento al final de una lista");
	pa2m_afirmar(lista_tamanio(lista) == 4 && !lista_vacia(lista), "Al insertar un elemento al final de una lista el tamaño de la lista aumenta");
	pa2m_afirmar(lista_elemento_en_posicion(lista, 3) == &elemento4, "El elemento en la posicion es el insertado");
	pa2m_afirmar(lista_ultimo(lista) == &elemento4 && lista_primero(lista) == &elemento6, "El último de la lista y el primero son los correctos");

	pa2m_afirmar(lista_insertar_en_posicion(lista, &elemento7, 20) == lista && lista_ultimo(lista) == &elemento7, "Si la posicion no existe, se inserta al final");

	lista_destruir(lista);
}

void no_se_puede_quitar_en_una_lista_nula_o_vacia()
{
	pa2m_afirmar(lista_quitar(NULL) == NULL && lista_quitar_de_posicion(NULL, 2) == NULL, "No puedo quitar elementos de una lista nula");
	lista_t *lista = lista_crear();
	lista->cantidad = 0;

	pa2m_afirmar(lista_quitar(lista) == NULL && lista_quitar_de_posicion(lista, 2) == NULL, "No puedo quitar elementos de una lista vacía");

	lista_destruir(lista);
}

void quito_un_elemento_y_disminuye_el_tamanio_de_la_lista()
{
	lista_t *lista = lista_crear();

	char elemento1 = 'a';
	char elemento2 = 'b';
	char elemento3 = 'c';
	char elemento4 = 'd';

	lista_insertar(lista, &elemento1);
	lista_insertar(lista, &elemento2);
	lista_insertar(lista, &elemento3);
	lista_insertar(lista, &elemento4);

	pa2m_afirmar(lista_quitar_de_posicion(lista, 2) == &elemento3, "Puedo quitar un elemento del medio de la lista");
	pa2m_afirmar(lista_tamanio(lista) == 3, "Al quitar un elemento, el tamaño de la lista disminuye");
	pa2m_afirmar(lista_primero(lista) == &elemento1 && lista_ultimo(lista) == &elemento4, "El primero y el ultimo de la lista son los correctos");

	pa2m_afirmar(lista_quitar(lista) == &elemento4, "Puedo quitar un elemento del final de la lista");
	pa2m_afirmar(lista_tamanio(lista) == 2, "Al quitar un elemento, el tamaño de la lista disminuye");
	pa2m_afirmar(lista_primero(lista) == &elemento1 && lista_ultimo(lista) == &elemento2, "El primero y el ultimo de la lista son los correctos");

	pa2m_afirmar(lista_quitar_de_posicion(lista, 0) == &elemento1, "Puedo quitar un elemento del principio de la lista");
	pa2m_afirmar(lista_tamanio(lista) == 1, "Al quitar un elemento, el tamaño de la lista disminuye");
	pa2m_afirmar(lista_primero(lista) == &elemento2 && lista_ultimo(lista) == &elemento2, "El primero y el ultimo de la lista son los correctos");

	lista_destruir(lista);
}

void creo_un_iterador_y_me_devuelve_un_iterador_valido()
{
	lista_t *lista = lista_crear();
	char elemento = 'a';
	lista_insertar(lista, &elemento);

	lista_iterador_t *iterador = lista_iterador_crear(lista);

	pa2m_afirmar(lista_iterador_crear(NULL) == NULL, "No se puede crear un iterador de una lista nula");
	pa2m_afirmar(iterador != NULL && iterador->corriente == lista->nodo_inicio && iterador->lista == lista, "Creo un iterador y me devuelve un iterador válido");

	pa2m_afirmar(lista_iterador_elemento_actual(iterador) == lista->nodo_inicio->elemento, "Al crear un iterador, el elemento actual es el primer elemento de la lista");

	lista_iterador_destruir(iterador);
	lista_destruir(lista);
}

void no_se_puede_avanzar_el_iterador_si_no_tiene_siguiente()
{
	lista_t *lista = lista_crear();

	lista_iterador_t *iterador = lista_iterador_crear(lista);

	pa2m_afirmar(lista_iterador_tiene_siguiente(iterador) == false && lista_iterador_avanzar(iterador) == false, "No se puede avanzar un iterador si no tiene siguiente");	

	lista_iterador_destruir(iterador);
	lista_destruir(lista);
}

void no_se_puede_avanzar_en_un_iterador_nulo()
{
	pa2m_afirmar(lista_iterador_avanzar(NULL) == false, "No se puede avanzar en un iterador nulo");
}

int main() {

	pa2m_nuevo_grupo("Pruebas de creación de pila");
  	creo_una_pila_y_devuelve_una_pila_vacia_con_tope_nulo();

  	pa2m_nuevo_grupo("Pruebas de apilar");
	apilo_un_elemento_y_se_incrementa_el_tamanio_de_la_pila();
	puedo_apilar_un_elemento_NULL();
	no_se_puede_apilar_en_una_pila_nula();

	pa2m_nuevo_grupo("Pruebas de desapilar");
	desapilo_un_elemento_y_disminuye_el_tamanio_de_la_pila();
	no_se_puede_desapilar_en_una_pila_nula();

	pa2m_nuevo_grupo("Pruebas de creación de cola");
  	creo_una_cola_y_devuelve_una_cola_vacia_con_frente_nulo();

	pa2m_nuevo_grupo("Pruebas de encolar");

	pa2m_nuevo_grupo("Pruebas de creación de lista");
	creo_una_lista_y_me_devuelve_una_lista_vacía_con_principio_y_fin_nulos();

	pa2m_nuevo_grupo("Pruebas de insertar al final en lista");
	no_se_puede_insertar_en_una_lista_nula();
	inserto_un_elemento_al_final_y_se_incrementa_el_tamanio_de_la_lista();

	pa2m_nuevo_grupo("Pruebas de insertar en posicion en lista");
	no_se_puede_insertar_en_una_lista_nula();
	inserto_un_elemento_y_se_incrementa_el_tamanio_de_la_lista();

	pa2m_nuevo_grupo("Pruebas de quitar al final en lista");
	no_se_puede_quitar_en_una_lista_nula_o_vacia();
	quito_un_elemento_y_disminuye_el_tamanio_de_la_lista();

	pa2m_nuevo_grupo("Pruebas de iterador");
	creo_un_iterador_y_me_devuelve_un_iterador_valido();
	no_se_puede_avanzar_el_iterador_si_no_tiene_siguiente();
	no_se_puede_avanzar_en_un_iterador_nulo();

  	return pa2m_mostrar_reporte();
}
