// We know that to apply topological sort, we need a DAG
// So, if we are given a DCG, the topo sort wouldnt work
// If the topo sort isnt of N size, that means it was a DCG


// code for the same : 

// if(topo.size() == N) return false;
// else return true;