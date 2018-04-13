void Graph::findNodeWithMaximumAdjacent(int startVertex) {
	// q helps determine the breadth first traversal
	queue<vertex*> q;
	// maxAdj contains a running list of the 'maximum adjacent' nodes
	vector<vertex*> maxAdj;

	// make sure the vertices have 'visited' set to false
	vertex *start;
	for (int i = 0; i < (int)vertices.size(); i++) {
		vertices[i].visited = false;
		if (vertices[i].value == startVertex) {
			start = &vertices[i];
		}
	}
    // handle the starting node
	q.push( start);
	vertex * cur = q.front();
	cur->visited = true;
	cout << cur->value << ' ';
	int max = cur->adj.size();
	maxAdj.push_back(cur);

	// main loop
	while( !q.empty() ) {
		cur = q.front();
		q.pop();

		// for each of the current node's unvisited
		// neighbors, push, print, and visit
		for(int i = 0; i < (int)cur->adj.size(); ++i){
			if(cur->adj[i].v->visited == false){
				q.push(cur->adj[i].v);
				cur->adj[i].v->visited = true;
				cout << cur->adj[i].v->value << ' ';
				int size = cur->adj[i].v->adj.size();
				// if a node has more adjacencies than the current max,
				// clear maxAdj and push back the new max adjacent node
				if(size > max){
					max = size;
					maxAdj.clear();
					maxAdj.push_back(cur->adj[i].v);
				}
				// otherwise if a node has the same number of adjacencies
				// as the current max, simply add it to the end of the
				// maxAdj vector
				else if(size==max)
					maxAdj.push_back(cur->adj[i].v);
			}
		}
	}
	cout << endl;

	// print final list of 'maximum adjacent' nodes
	for(int i = 0; i < (int)maxAdj.size(); ++i)
		cout << maxAdj[i]->value << ' ';
	cout << endl;
}
