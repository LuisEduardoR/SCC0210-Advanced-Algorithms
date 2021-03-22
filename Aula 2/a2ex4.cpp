/*

It’s finally christmas and Tom has been waiting for Santa
Claus all year! This year he was a good boy and he won
a load of presents. There were m boxes under his tree,
but Santa Claus surprised him, and some boxes have
other boxes inside them. So a box has either other
boxes inside it or a toy. All boxes have different sizes,
but Tom likes big boxes, so the first present he will open
will be the largest, and after opening some box i, he will
choose the largest between the presents he had before
opening i and the ones revealed by i. However, there
are many boxes, and after opening k presents Tom will get tired. Find out how many
toys did Tom get before he got tired.

Input:
The first line contains integers n (1 <= n <= 105), m (1 <= m ,+ n) and k (1 <= k <= n), 
the total number of presents, the number of boxes under Tom’s tree and how many
boxes Tom can open before he gets tired, respectively.
The second line has n distinct integers si, representing the size of i-th box
(1 <= si <= 109). Note that in this problem box x within y can have size greater than y.
The i-th of the next n lines contains integer qi, followed by qi integers
representing the ID of boxes that are inside box i. If qi is 0, that means i-th box has a
toy inside it!
The fourth and last line has m integers representing the IDs of boxes that are
under Tom’s tree.
Output
You should output a single line containing how many toys did Tom get after opening
k boxes.

Sample Input:
10 2 6 
1 30 14 11 4 6 2 2 5 1
0
2 3 4
0
2 5 6
2 7 8
2 9 10
0
0
0
0
1 2

Sample Output:
2

*/

#include <vector>
#include <queue>
#include <utility>
#include <cstdio>

using namespace std;

struct box {

	int size;
	bool has_present;
	bool contained;
	vector<int> boxes_contained;

	box() {

		size = 0;
		has_present = false;
		contained = false;

	}	

};

int main(void) {

	int n, m, k;
	scanf(" %d %d %d", &n, &m, &k);	

	vector<box> boxes;
	for(int i = 0; i <= n; i++) {

		box b = box();
		boxes.push_back(b);

	}

	for(int i = 1; i <= n; i++) {

		int t_size;
		scanf(" %d", &t_size);
		boxes[i].size = t_size;

	}

	for(int i = 1; i <= n; i++) {

		int q;
		scanf(" %d", &q);

		if(q > 0) {

			boxes[i].has_present = false;
			for(int j = 0; j < q; j++) {
			
				int q_c;
				scanf(" %d", &q_c);

				boxes[q_c].contained = true;
				boxes[i].boxes_contained.push_back(q_c);

			}

		} else {
			boxes[i].has_present = true;
		}
	}

	priority_queue<pair<int, int>> tree;
	for(int i = 1; i <= m; i++) {

		int temp;
		scanf(" %d", &temp);
		tree.push(make_pair(boxes[temp].size, temp));

	}

	int energy = k;
	int toys = 0;
	while(energy > 0) {

		int id = (tree.top()).second;
		tree.pop();

		if(boxes[id].has_present)
			toys++;
		else {
			for(size_t i = 0; i < boxes[id].boxes_contained.size(); i++)
				tree.push(make_pair(boxes[boxes[id].boxes_contained[i]].size, boxes[id].boxes_contained[i]));
		}

		energy--;

	}

	printf("%d\n", toys);

	return 0;
}
