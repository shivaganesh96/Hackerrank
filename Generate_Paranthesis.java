//https://leetcode.com/problems/generate-parentheses/description/
class Solution {
  
    public  void helper(String init,int n, int open, int closed, List<String> list){
        if(closed == n){
            list.add(init);
        }
        if(closed < open){
            helper(init+")",n,open,closed+1,list);
        }
        if(open < n){
            helper(init+"(",n,open+1,closed,list);
        }
        
    }
    public List<String> generateParenthesis(int n) {
         ArrayList <String> list = new ArrayList<String>();
        helper("",n,0,0,list);
        return list;
        
        
    }
}
