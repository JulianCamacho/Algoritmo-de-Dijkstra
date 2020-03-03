#include "auxclass.h"
#include <bits/stdc++.h>
#include <fstream>
#include <istream>
#include <sstream>
#include <string>
#include <QString>
#define INF 999

using namespace std;

int vertArr[20][20]; /**< TODO: describe */
int count = 0; /**< TODO: describe */
int src, target; /**< TODO: describe */
int dist[100]; /**< TODO: describe */
bool visited[100]; /**< TODO: describe */
int parent[100]; /**< TODO: describe */

/**
 * @brief Constructor para la clase grafo.
 *
 * @param source Nodo desde el que se desea calcular el camino más corto.
 * @param targett Nodo de destino para calcular Dijkstra.
 * @param file_name Nombre del archivo donde se encuentra el grafo.
 */
Graph::Graph(int source, int targett, string file_name){
    generateGraph(file_name);
    this->src = source;
    this->target = targett;
    init();
    dijkstra();
}

/**
 * @brief Función para inicializar el grafo según la lectura del archivo.
 *
 * @param file_name Nombre del archivo donde se encuentra del grafo.
 */
void Graph::generateGraph(string file_name){
    for(int i = 0; i<20; i++){
        for (int j = 0; j<20; j++){
            vertArr[i][j] = INF;
        }
    }
    ifstream infile(file_name);
    cout << file_name << endl;
    if (!infile.is_open()){
        return;
    }
    string node1, node2, weight, vert;
    int node1int, node2int, weightInt, intVert;
    string line;
    bool flag = false;
    while(getline(infile, line)){
        try {
            if (flag == false){
                stringstream ss(line);
                getline(ss, vert, ',');
                intVert = stoi(vert);
                cout << intVert << endl;
                this->vertices = intVert;
                flag = true;
            } else{
                stringstream ss(line);
                getline(ss, node1, ',');
                getline(ss, node2, ',');
                getline(ss, weight, ',');
                node1int = stoi(node1);
                node2int = stoi(node2);
                weightInt = stoi(weight);
                add_edge(node1int, node2int, weightInt);
            }
        } catch (invalid_argument) {
            cout << "Se detuvo el proceso" << endl;

        }
    }

    infile.close();
}


/**
 * @brief Función para agregar los pesos entre los nodos.
 *
 * @param u Nodo de salida.
 * @param v Nodo de destino.
 * @param weight Peso entre los nodos.
 */
void Graph::add_edge(int u, int v, int weight) {
   vertArr[u][v] = weight;
   vertArr[v][u] = weight;
}

/**
 * @brief Función para desplegar el grafo en consola.
 *
 * @param v Cantidad de vértices.
 */
void Graph::displayMatrix(int v) {
   int i, j;
   for(i = 0; i < v; i++) {
      for(j = 0; j < v; j++) {
         cout << vertArr[i][j] << " ";
      }
      cout << endl;
   }
}


/**
 * @brief Función para inicializar las distancias entre nodos en infinito.
 *
 */
void Graph::init(){
    for (int i=0; i<vertices; i++){
        parent[i] = i;
        dist[i] = INF;
    }
    dist[src] = 0;
}

/**
 * @brief Función para encontrar el nodo más cercano.
 *
 * @return int Nodo más cercano.
 */
int Graph::getNearest(){
    int minvalue = INF;
    int minnode = 0;
    for(int i =0; i<vertices; i++){
        if (!visited[i] && dist[i] < minvalue){
            minvalue = dist[i];
            minnode = i;
        }
    }
    return minnode;
}

/**
 * @brief Función que realiza el algoritmo de Dijkstra.
 *
 */
void Graph::dijkstra(){
    cout << vertices << endl;
    for (int i=0; i<vertices; i++){
        int nearest = getNearest();
        visited[nearest] = true;
        for (int adj = 0; adj < vertices; adj++){
            if ((vertArr[nearest][adj] != INF) && (dist[adj] > dist[nearest]+vertArr[nearest][adj])){
                dist[adj] = dist[nearest]+vertArr[nearest][adj];
                parent[adj] = nearest;
            }
        }
    }
}

/**
 * @brief Función para desplegar el resultado del camino más corto que se debe seguir.
 *
 */
string Graph::display(){
    string result;
    cout << src << endl;
    cout << target << endl;

    int parnode = parent[target];
    result += to_string(target);
    cout << target;
    while (parnode != src){
        result += " <-- ";
        result += to_string(parnode);
        result += " ";
        cout << " <-- " << parnode << " ";
        parnode = parent[parnode];
    }
    result += "<--";
    result += to_string(src);
    cout << " <-- " << src << endl;
    cout << result << " ay el bicho" << endl;
    return result;
}



