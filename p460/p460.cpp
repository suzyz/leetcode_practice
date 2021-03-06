// pretty messed up code written when I was really sleepy. T_T
// the second version is much more cleaner and makes more sense.
#include <iostream>
#include <map>
#include <set>
#include <utility>

using namespace std;

class LFUCache {
public:
	int clock, cap;
	map<int, int> values;
	map<int, int> freqs;
	map<int, int> lastVisitTime;
	map<int, set<pair<int,int> > > mapFreqToKeys;

    LFUCache(int capacity) {
    	clock = 0;
        cap = capacity;
    }
    
    int get(int key) {
    	if (cap == 0)
    		return -1;

    	clock++;

        if (!values.count(key))
        	return -1;
        
        int v = values[key];
        incFreq(key);

        // cout << "get:" << key << endl;
        // cout << "lastVisitTime:" << endl;
        // for (std::map<int,int>::iterator i = lastVisitTime.begin(); i != lastVisitTime.end(); ++i)
        // 	cout << i->first << ":" << i->second << endl;
        // cout << endl;

        return v;
    }
    
    void put(int key, int value) {
    	if (cap == 0)
    		return;

    	clock++;

 		// cout << "put: " << key << "," << value << " clock:" << clock << endl;

    	if ((values.count(key) && values.size() > cap) || 
    		(!values.count(key) && values.size() >= cap)) {
        	int targetKey = mapFreqToKeys.begin()->second.begin()->second;

        	// cout <<  mapFreqToKeys.begin()->second.begin()->first << endl;
        	// cout << "evict:" << targetKey << endl;
        	mapFreqToKeys.begin()->second.erase(mapFreqToKeys.begin()->second.begin());
        	if (mapFreqToKeys.begin()->second.size() == 0)
        		mapFreqToKeys.erase(mapFreqToKeys.begin());
        	freqs.erase(targetKey);
        	values.erase(targetKey);
        	lastVisitTime.erase(targetKey);
        }

      	values[key] = value;
        incFreq(key);
    }

    void incFreq(int key) {
    	int oldFreq = freqs[key];
        freqs[key]++;

        // cout << "lastVisitTime:" << endl;
        // for (std::map<int,int>::iterator i = lastVisitTime.begin(); i != lastVisitTime.end(); ++i)
        // 	cout << i->first << ":" << i->second << endl;
        // cout <<" ------ "<< endl;

        if (oldFreq > 0) {
			// time complexity: log !!

        	mapFreqToKeys[oldFreq].erase(make_pair(lastVisitTime[key], key));
        
        	if (mapFreqToKeys[oldFreq].size() == 0)
        		mapFreqToKeys.erase(oldFreq);
        }
        	 
        mapFreqToKeys[oldFreq+1].insert(make_pair(clock, key));

        lastVisitTime[key] = clock;

        // cout << "mapFreqToKeys:" << endl;
       	// for (std::map<int,set<pair<int,int> > >::iterator i = mapFreqToKeys.begin(); i != mapFreqToKeys.end(); ++i) {
       	// 	cout << "freq == " << i->first << ":" << endl;
       	// 	for (std::set<pair<int,int> >::iterator j = i->second.begin(); j != i->second.end(); ++j)
       	// 		cout << j->first << ":" << j->second << endl;
       	// }
       	// cout <<" ------ " << endl;
    }
};

int main(int argc, char const *argv[])
{
	// LFUCache obj(2);
	// obj.put(1,1);
	// obj.put(2,2);
	// cout << obj.get(1) << endl;
	// obj.put(3,3);
	// cout << obj.get(2) << endl;
	// cout << obj.get(3) << endl;

	// obj.put(5,5);
	// cout << obj.get(1) << endl;
	// cout << obj.get(3) << endl;
	// cout << obj.get(5) << endl;

	////////////////////////////////////////////
	// LFUCache obj(0);
	// obj.put(0,0);
	// cout << obj.get(0) << endl;

	////////////////////////////////////////////
	// ["LFUCache","put","put","get","put","put","get"]
	// [[2],[2,1],[2,2],[2],[1,1],[4,1],[2]]
	// LFUCache obj(2);
	// obj.put(2,1);
	// obj.put(2,2);
	// cout << obj.get(2) << endl;
	// obj.put(1,1);
	// obj.put(4,1);
	// cout << obj.get(2) << endl;

	////////////////////////////////////////////
	// ["LFUCache","put","put","get","put","get","get","put","get","get","get"]
	// [[2],[1,1],[2,2],[1],[3,3],[2],[3],[4,4],[1],[3],[4]]
	// LFUCache obj(2);
	// obj.put(1,1);
	// obj.put(2,2);
	// cout << obj.get(1) << endl;
	// obj.put(3,3);
	// cout << obj.get(2) << endl;
	// cout << obj.get(3) << endl;
	// obj.put(4,4);
	// cout << obj.get(1) << endl;
	// cout << obj.get(3) << endl;
	// cout << obj.get(4) << endl;

	////////////////////////////////////////////
	// ["LFUCache","get","put","get","put","put","get","get"]
	// [[2],[2],[2,6],[1],[1,5],[1,2],[1],[2]]
	// LFUCache obj(2);
	// cout << obj.get(2) << endl;
	// obj.put(2,6);
	// cout << obj.get(1) << endl;
	// obj.put(1,5);
	// obj.put(1,2);
	// cout << obj.get(1) << endl;
	// cout << obj.get(2) << endl;
	
	////////////////////////////////////////////
	//["LFUCache","put","put","put","put","put","get","put","get","get","put","get","put","put","put","get","put","get","get","get","get","put","put","get","get","get","put","put","get","put","get","put","get","get","get","put","put","put","get","put","get","get","put","put","get","put","put","put","put","get","put","put","get","put","put","get","put","put","put","put","put","get","put","put","get","put","get","get","get","put","get","get","put","put","put","put","get","put","put","put","put","get","get","get","put","put","put","get","put","put","put","get","put","put","put","get","get","get","put","put","put","put","get","put","put","put","put","put","put","put"]
	//[[10],[10,13],[3,17],[6,11],[10,5],[9,10],[13],[2,19],[2],[3],[5,25],
	// [8],[9,22],[5,5],[1,30],[11],[9,12],[7],[5],[8],[9],[4,30],[9,3],
	// [9],[10],[10],[6,14],[3,1],[3],[10,11],[8],[2,14],[1],[5],[4],[11,4],[12,24],[5,18],[13],[7,23],[8],[12],[3,27],[2,12],[5],[2,9],[13,4],[8,18],[1,7],[6],[9,29],[8,21],[5],[6,30],[1,12],[10],[4,15],[7,22],[11,26],[8,17],[9,29],[5],[3,4],[11,30],[12],[4,29],[3],[9],[6],[3,4],[1],[10],[3,29],[10,28],[1,20],[11,13],[3],[3,12],[3,8],[10,9],[3,26],[8],[7],[5],[13,17],[2,27],[11,15],[12],[9,19],[2,15],[3,16],[1],[12,17],[9,1],[6,19],[4],[5],[5],[8,1],[11,7],[5,2],[9,28],[1],[2,2],[7,4],[4,22],[7,24],[9,26],[13,28],[11,26]]


	return 0;
}