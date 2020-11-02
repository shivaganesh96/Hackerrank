// Leetcode 210. Course Schedule II


class Solution {
    
    public void helper(HashMap<Integer,LinkedList<Integer>> adj, HashSet<Integer> visited, Stack<Integer> s, int curr){
        if(visited.contains(curr)){
            return;
        }
        int val;
        visited.add(curr);
        LinkedList<Integer> n = adj.get(curr);
            while(n!=null && !n.isEmpty()){
                val = n.removeFirst();
                if(!visited.contains(val)){
                    helper(adj,visited,s,val);
                }
            }
        s.push(curr);
        return;   
    }
    
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        HashMap<Integer,LinkedList<Integer>> adj = new HashMap<Integer,LinkedList<Integer>>();
        int[] ingress = new int[numCourses];
        Arrays.fill(ingress,0);
        
        //Setting up graph
        for(int i=0;i<prerequisites.length;i++){
            if(adj.containsKey(prerequisites[i][1]) && adj.get(prerequisites[i][1]).contains(prerequisites[i][0])){
                return new int[0];
            }
            if(adj.containsKey(prerequisites[i][0])){
                LinkedList<Integer> temp  = adj.get(prerequisites[i][0]);
                temp.add(prerequisites[i][1]);
                adj.put(prerequisites[i][0],temp);
                ingress[prerequisites[i][1]]++;
            }
            else{
                LinkedList<Integer> temp = new LinkedList<Integer>();
                temp.add(prerequisites[i][1]);
                adj.put(prerequisites[i][0],temp);
                ingress[prerequisites[i][1]]++;
            }         
        }
        
        HashSet<Integer> starts = new HashSet<Integer>();
        //Finding start nodes.
        for(int i=0;i<ingress.length;i++){
            if(ingress[i]==0){
                System.out.println(i);
                starts.add(i);
            }
        }
        
        Stack<Integer> stack = new Stack<Integer>();
        HashSet<Integer> visited = new HashSet<Integer>();
        
        for(int x : starts ){
            if(!visited.contains(x))
            helper(adj,visited,stack,x);
        }
        
        if(stack.size() != numCourses){
            
            return new int[0];
        }
        
        int[] result = new int[numCourses];
        
        for(int i=numCourses-1;i>=0;i--){
            result[i] = stack.pop();
        }
        
        return result;
            
    }
}

