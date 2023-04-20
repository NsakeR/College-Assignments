///////////////////////////////////////////////////////////////////////////////////
//
//  Program znajdujący ilość kursów oparty o algorytm Kruskala w grafie
//  
//  Autor: Jakub Lefik
//  Data: 11.05.2021   Wersja: 1.0
//  Data: 21.04.2021   Wersja: 1.1 - poprawiono algorytm Kruskala
//
//////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <vector>
#include <map>
#include <queue>

class Edge {            
public:
    int vertex1;        // pierwszy wierzchołek drogi
    int vertex2;        // drugi wierzchołek drogi
    int weight;         // dlugosc krawędzi między nimi

    bool operator< (const Edge& e) const;
    
    //----- 4 żelazne metody + parametrowy -----// 

    Edge();
    Edge(const Edge& copy);
    Edge& operator= (const Edge& e);
    ~Edge() {};
    Edge(int one, int two, int three);

    void setVertex1(int v);
    void setVertex2(int v);
    void setWeight(int w);

    int getVertex1();
    int getVertex2();
    int getWeight();

};

bool Edge::operator<(const Edge& e) const 
{
    return weight < e.weight;
}

Edge::Edge() : vertex1(0),
vertex2(0),
weight(0)
{
}

Edge::Edge(const Edge& copy) : vertex1(copy.vertex1), 
vertex2(copy.vertex2),
weight(copy.weight)
{
}

Edge& Edge::operator=(const Edge& e)
{
    this->vertex1 = e.vertex1;
    this->vertex2 = e.vertex2;
    this->weight = e.weight;
    return *this;
}

Edge::Edge(int one, int two, int three) : vertex1(one),
vertex2(two),
weight(three)
{
}

void Edge::setVertex1(int v)
{
    this->vertex1 = v;
}

void Edge::setVertex2(int v)
{
    this->vertex2 = v;
}

void Edge::setWeight(int w)
{
    this->weight = w;
}

int Edge::getVertex1()
{
    return this->vertex1;
}

int Edge::getVertex2()
{
    return this->vertex2;
}

int Edge::getWeight()
{
    return this->weight;
}

class Graph : public Edge {

public: 
    //----- 4 żelazne metody + parametrowy -----// 
    Graph();
    Graph(const Graph& copy);
    ~Graph() {};
    Graph& operator= (const Graph& g);

    Graph(int vertexes, int roads);

    void add(const Edge& edge);         // Metoda dodająca do vectora krawędzi          
    Graph kruskal();                    // algorytm kruskala

    int lowestEdgeInPath(int vert1, int vert2);     // algorytm znajdujący najkrótszą drogę w trasie (do dopracowania)
    void show();

private:
    int vertexes;
    int edges;
    std::vector<std::vector<Edge>> road;
};

Graph::Graph() : vertexes(0),
edges(0), road(0)
{
}

Graph::Graph(const Graph& copy) : vertexes(copy.vertexes), 
edges(copy.edges), road(copy.road)
{
}

Graph& Graph::operator=(const Graph& g)
{
    this->vertexes = g.vertexes;
    this->edges = g.edges;
    this->road = g.road;
    return *this;
}

Graph::Graph(int v, int r) : vertexes(v), edges(r) {

    road.assign(vertexes + 1, {});
}

void Graph::add(const Edge& edge)
{
    road[edge.vertex1].push_back({ edge.vertex1, edge.vertex2,edge.weight });
}

Graph Graph::kruskal() {
    
    Graph tree(vertexes, edges);
    Edge abcd;
    std::priority_queue<Edge> prio_queue;

    std::vector<bool> checked(vertexes + 1, false);

    int vert = 1;
    checked[vert] = true;

    for (int i = 2; i <= vertexes; i++) {
        for (auto& iteratingVertex : road[vert]) {
            if (checked[iteratingVertex.vertex2] == false) {
                prio_queue.push(iteratingVertex);
            }
        }

        abcd = prio_queue.top();  // przepisywanie trasy
        prio_queue.pop();

        while (checked[abcd.vertex2]) {
            abcd = prio_queue.top();
            prio_queue.pop();
        }


        tree.add(abcd);
        checked[abcd.vertex2] = true;
        vert = abcd.vertex2;

    }
    return tree;
}

int Graph::lowestEdgeInPath(int vert1, int vert2) {
    std::map<int, Edge> maps;
    std::vector<Edge> abc;
    std::vector<bool> checked(vertexes + 1, false);
    checked[vert1] = true;   
    abc.push_back({ vert1, vert1, 0 });
    int min = 2000000000;

    if (vert1 == vert2) {
        return 0; 
    }

    do {
        Edge iteratingVertex = abc.back();
        abc.pop_back();
        if (vert2 == iteratingVertex.vertex2) {
            break;
        }
        
        for (auto& iteratingEdge : road[iteratingVertex.vertex2]) {

            if (checked[iteratingEdge.vertex2] == false) {

                abc.push_back(iteratingEdge);
                checked[iteratingEdge.vertex2] = true;
                maps[iteratingEdge.vertex2] = iteratingEdge;

            }
        }
    } while (abc.empty() == false);

    do {
        if (maps[vert2].weight < min) {
            min = maps[vert2].weight;
        }
        vert2 = maps[vert2].vertex1;
    } while (vert2 != vert1);

    return min;
}

void Graph::show()
{
    for (auto& i : road) {
        for (auto& j : i) {
            std::cout << j.vertex1 << " " << j.vertex2 << " " << j.weight << std::endl;
        }
    }
}

int main()
{
    int numOfCities = 0, numOfRoads = 0;
    int numberOfKursy = 0;
    int end1 = 1, end2 = 1;
    int city1 = 0, city2 = 0;
    int startCity = 0;
    int finalCity = 0;
    int numOfPass = 0;
    int numOfSeats = 0;

        std::cin >> numOfCities;
        std::cin >> numOfRoads;
        std::vector<Edge> hold;
        Graph graph(numOfCities, numOfRoads);

        for (int i = 0; i < numOfRoads; i++) {
            std::cin >> city1 >> city2 >> numOfPass;
            graph.add({ city1, city2, numOfPass });
        }        

        Graph a = graph.kruskal();

        std::cin >> startCity;
        std::cin >> finalCity;

        do {
            std::cin >> numOfPass;
        
            numOfSeats = a.lowestEdgeInPath(startCity, finalCity);
            numOfSeats = numOfSeats - 1;            // trzeba wliczyć kierowce w liste osob 
            if (numOfPass % numOfSeats == 0) {
                numberOfKursy = numOfPass / numOfSeats;
                std::cout << numberOfKursy;
            }
            else {
                numberOfKursy = (numOfPass / numOfSeats) + 1;
                std::cout << numberOfKursy;
            }

            std::cin >> end1;
            std::cin >> end2;

        } while (end1 != 0 && end2 != 0);
    
    return 0;
}

