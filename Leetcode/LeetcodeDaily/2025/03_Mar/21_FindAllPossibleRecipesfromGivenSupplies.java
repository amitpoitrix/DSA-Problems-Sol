/**
 * 2115. Find All Possible Recipes from Given Supplies
 * Link: https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/description/?envType=daily-question&envId=2025-03-21
 * YT: https://www.youtube.com/watch?v=4Tixc5mU-Pk
 * 
 * 
 * Approach 1: Bruteforce Approach
 * Store the supplies in set and whenever any recipe can be made add it in supplies_set
 * Take a boolean[] of size n (i.e., recipes.length) and store true if recipe can be made.
 * Run a while loop till n which keep on populating above boolean[] in all possible ways even though any recipe which will come in future
 * and can be part of ingredient for another recipe
 * Inside while loop we'll treverse over recipes[] and for each recipes[i] we'll traverse over ingredients[i].size() if supplies have all 
 * the ingredients if yes than will mark the boolean[] of ith recipes as true and add this recipes[i] in supplies_set.
 * After while loop traverse over boolean[] array and form the resultant list of recipes which can be made
 * 
 * Summary:
 * Iterates over the recipes multiple times, checking if all ingredients are available in the supply set. 
 * If a recipe can be made, it is added to the supply and result list. 
 * Repeats until no more recipes can be formed.
 * 
 * Complexity:
 * Time: O(n * n * m)
 * Sapce: O(n)
 */
class Solution1 {
    public List<String> findAllRecipes(String[] recipes, List<List<String>> ingredients, String[] supplies) {
        // Approach 1: Brute force Approach

        int n = recipes.length;

        Set<String> set = new HashSet<>();
        for(String supply: supplies) {
            set.add(supply);
        }

        boolean[] contains = new boolean[n];

        int count = n;

        // O(n * n * m)
        while(count-- > 0) {
            for(int i = 0; i < n; i++) { // O(n * m)
                if(contains[i] == true) {
                    continue;
                }

                boolean canMade = true;
                for(int j = 0; j < ingredients.get(i).size(); j++) {    // O(m)
                    if(!set.contains(ingredients.get(i).get(j))) {
                        canMade = false;
                        break;
                    }
                }

                if(canMade == true) {
                    contains[i] = true;
                    set.add(recipes[i]);
                }
            }
        }

        List<String> result = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            if(contains[i] == true) {
                result.add(recipes[i]);
            }
        }

        return result;
    }
}


/**
 * Approach 2: Using Graph
 * 
 * Now here in this ques we've to find all the recipes that can be made using ingredients[i] but these ingredients[i] should be present in 
 * supplies or in our resultant list in order to make current recipes[i]
 * Now there is this possibility that ingredients[i] might contain some ingredients that is not there in supplies but its there in future 
 * recipes[j] (which can be made as all its ingredients will be there in supplies)
 * So here we need to maintain proper ordering of all supplies & recipes[k](already made one) in order to satisfy all ingredients[i] for current recipes[i] to make.
 * So we can make use of Topological sort here as there is need of ordering
 * there is relation like ingredient --> recipe means recipe will only be created if ingredient is there means there is this dependency of recipe on ingredient
 * So in this way we can create Graph<ingredient, {list of recipes indexes}> for those ingredients which is not there in supply and these 
 * ingredients will be needed by those recipes which we didn't get created before
 * 
 * Complexity:
 * Time: O(N * M + E)
 * Space: O(N)
 */

class Solution2 {
    public List<String> findAllRecipes(String[] recipes, List<List<String>> ingredients, String[] supplies) {
        // Approach 2:
        
        // Step 1: Adding all the supplies in set for checking ingredients in O(1)
        Set<String> set = new HashSet<>();
        for(String supply: supplies) {
            set.add(supply);
        }
        
        // Step 2: Create adjacency list for graph using map as we need Graph<ingredient_not_present_supply, {list of recipes idx dependent on this ingredient}>
        Map<String, List<Integer>> adj = new HashMap<>();

        int n = recipes.length;

        // indegree[]
        int[] dependency = new int[n];

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < ingredients.get(i).size(); j++) {

                String ingredient = ingredients.get(i).get(j);

                if(!set.contains(ingredient)) {
                    List<Integer> recipeIdx;

                    if(adj.containsKey(ingredient)) {
                        recipeIdx = adj.get(ingredient);
                    } else {
                        recipeIdx = new ArrayList<>();
                    }

                    recipeIdx.add(i);
                    adj.put(ingredient, recipeIdx);

                    // Adding current recipe idx in indegree[] alias dependency[]
                    dependency[i]++;
                }
            }
        }

        Queue<String> queue = new LinkedList<>();

        // Adding those recipes in queue whose dependency is 0
        for(int i = 0; i < n; i++) {
            if(dependency[i] == 0) {
                queue.offer(recipes[i]);
            }
        }

        List<String> result = new ArrayList<>();

        while(!queue.isEmpty()) {
            String currentRecipe = queue.poll();
            result.add(currentRecipe);

            if(adj.containsKey(currentRecipe)) {
                // Now checking its neighbouring nodes
                for(Integer idx: adj.get(currentRecipe)) {
                    // As currentRecipe is already created so reducing dependency count of adjacent recipe's idx by 1
                    dependency[idx]--;

                    if(dependency[idx] == 0) {
                        queue.offer(recipes[idx]);
                    }
                }
            }
        }

        return result;
    }
}