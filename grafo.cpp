#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
#define MAX 10005 
#define Node pair< int , int > 
#define INF 1<<30 
struct cmp {
    bool operator() ( const Node &a , const Node &b ) {
        return a.second > b.second;
    }
};
vector< Node > ady[ MAX ]; 
int distancia[ MAX ];      
bool visitado[ MAX ];      
priority_queue< Node , vector<Node> , cmp > Q; 
int V;                     
int previo[ MAX ];         
void init(){
    for( int i = 0 ; i <= V ; ++i ){
        distancia[ i ] = INF;  
        visitado[ i ] = false; 
        previo[ i ] = -1;      
    }
}
void relajacion( int actual , int adyacente , int peso ){
    
    if( distancia[ actual ] + peso < distancia[ adyacente ] ){
        distancia[ adyacente ] = distancia[ actual ] + peso;  
        previo[ adyacente ] = actual;                         
        Q.push( Node( adyacente , distancia[ adyacente ] ) ); 
    }
}
void print( int destino ){
    if( previo[ destino ] != -1 )    
        print( previo[ destino ] );  
    printf("%d " , destino );        
}
void dijkstra( int inicial ){
    init(); 
    Q.push( Node( inicial , 0 ) ); 
    distancia[ inicial ] = 0;      
    int actual , adyacente , peso;
    while( !Q.empty() ){                   
        actual = Q.top().first;            
        Q.pop();                           
        if( visitado[ actual ] ) continue; 
        visitado[ actual ] = true;         

        for( int i = 0 ; i < ady[ actual ].size() ; ++i ){ 
            adyacente = ady[ actual ][ i ].first;   
            peso = ady[ actual ][ i ].second;        
            if( !visitado[ adyacente ] ){        
                relajacion( actual , adyacente , peso ); 
            }
        }
    }
    printf( "Distancias mas cortas iniciando en vertice %d\n" , inicial );
    for( int i = 1 ; i <= V ; ++i ){
        printf("Vertice %d , su distancia mas corta es: %d\n" , i , distancia[ i ] );
    }
    printf("\n\nIngrese el estado de destino: ");
    int destino;
    scanf("%d" , &destino );
    print(destino);
    printf("\n");
}
int main(){
    int inicial;
    V=26;
    ady[ 1 ].push_back( Node( 2 , 235 ) ); 
    ady[ 1 ].push_back( Node( 3 , 132 ) ); 
    ady[ 1 ].push_back( Node( 5 , 158 ) ); 
    ady[ 2 ].push_back( Node( 4 , 121 ) ); 
    ady[ 3 ].push_back( Node( 5 , 201 ) ); 
    ady[ 3 ].push_back( Node( 6 , 193 ) ); 
    ady[ 4 ].push_back( Node( 7 , 92 ) ); 
    ady[ 4 ].push_back( Node( 10 , 192 ) ); 
    ady[ 4 ].push_back( Node( 5 , 140 ) ); 
    ady[ 5 ].push_back( Node( 11 , 192 ) ); 
    ady[ 6 ].push_back( Node( 11 , 171 ) ); 
    ady[ 7 ].push_back( Node( 9 , 293 ) ); 
    ady[ 7 ].push_back( Node( 8 , 375 ) ); 
    ady[ 8 ].push_back( Node( 26 , 478 ) ); 
    ady[ 9 ].push_back( Node( 8 , 225 ) ); 
    ady[ 9 ].push_back( Node( 12 , 92 ) ); 
    ady[ 9 ].push_back( Node( 10 , 65 ) ); 
    ady[ 10 ].push_back( Node( 12 , 73 ) ); 
    ady[ 11 ].push_back( Node( 13 , 178 ) ); 
    ady[ 12 ].push_back( Node( 13 , 260 ) ); 
    ady[ 12 ].push_back( Node( 14 , 201 ) ); 
    ady[ 13 ].push_back( Node( 15 , 131 ) ); 
    ady[ 13 ].push_back( Node( 16 , 72 ) ); 
    ady[ 14 ].push_back( Node( 17 , 64 ) ); 
    ady[ 15 ].push_back( Node( 14 , 89 ) ); 
    ady[ 15 ].push_back( Node( 19 , 138 ) ); 
    ady[ 15 ].push_back( Node( 18 , 65 ) ); 
    ady[ 16 ].push_back( Node( 18 , 91 ) ); 
    ady[ 17 ].push_back( Node( 19 , 100 ) ); 
    ady[ 17 ].push_back( Node( 21 , 142 ) ); 
    ady[ 18 ].push_back( Node( 19 , 115 ) ); 
    ady[ 19 ].push_back( Node( 20 , 50 ) ); 
    ady[ 20 ].push_back( Node( 21 , 128 ) ); 
    ady[ 21 ].push_back( Node( 22 , 450 ) ); 
    ady[ 21 ].push_back( Node( 24 , 292 ) ); 
    ady[ 22 ].push_back( Node( 23 , 250 ) ); 
    ady[ 23 ].push_back( Node( 25 , 103 ) ); 
    ady[ 23 ].push_back( Node( 24 , 94 ) ); 
    ady[ 24 ].push_back( Node( 25 , 104 ) ); 
    ady[ 24 ].push_back( Node( 26 , 116 ) ); 
    ady[ 26 ].push_back( Node( 25 , 63 ) );    
    printf("1.-Malaga       14.-Salamanca\n");
	printf("2.-Cadiz        15.-Avila\n");
	printf("3.-Granada      16.-Madrid\n");
	printf("4.-Servilla     17.-Zamora\n");
	printf("5.-Cordoba      18.-Segovia\n");
	printf("6.-Jaen         19.-Valladolid\n");
	printf("7.-Huelva       20.-Palencia\n");
	printf("8.-Lisboa       21.-Leon\n");
	printf("9.-Badajos      22.-Oviedo\n");
	printf("10.-Nerida      23.-Lugo\n");
	printf("11.-C real      24.-Orense\n");
	printf("12.-Caceres     25.-Santiago\n");
	printf("13.-Toledo      26.-Pantevedra\n");
    printf("Ingrese el estado origen: ");
    scanf("%d" , &inicial );
    dijkstra( inicial );
    return 0;
}

