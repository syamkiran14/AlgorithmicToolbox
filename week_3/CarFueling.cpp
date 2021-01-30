#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops){
	vector<int> relative_distance;
	relative_distance.resize(stops.size());
	int current_node = 0;
	int car_index = 0;
	bool flag_1 = true;
	bool flag_2 = false;
	int best_index;
	int count = 0;
	int best_index_past;
	int timer = 0;
	while(1){
		if(dist - current_node <= tank){
			flag_2 = true;
			break;
		}
		for(int i = 0 ; i < stops.size() ; i++){
			relative_distance[i] = stops[i] - current_node;
		}
		best_index_past = best_index;
		for(int i = 0 ; i < stops.size() ; i++){
			if(relative_distance[i] > 0){
				if(tank - relative_distance[i] >= 0){
					if(flag_1){
						best_index = i;
						flag_1 = false;
					}
					else if((tank - relative_distance[best_index]) > (tank - relative_distance[i])){
						best_index = i;
					}
				}
			}
		}
		
		current_node = stops[best_index];
		count++;
		if(dist - current_node <= tank){
			flag_2 = true;
			break;
		}
		if(best_index_past == best_index){
			return -1;
		}
	}
	if(flag_2){
		return count;
	}
    return -1;
}


int main(){
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);
    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
