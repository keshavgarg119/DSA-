class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        int n = asteroids.size();

        for(int i = 0; i < n; i++) {
            if (asteroids[i] > 0) {
                st.push_back(asteroids[i]);
            } else {
                bool alive = true;

                while (!st.empty() && st.back() > 0 && st.back() < abs(asteroids[i])) {
                    st.pop_back();
                }

                // If equal size — both explode
                if (!st.empty() && st.back() == abs(asteroids[i])) {
                    st.pop_back();
                    alive = false;
                }
                // If no asteroid left or top is moving left — add current one
                else if (st.empty() || st.back() < 0) {
                    st.push_back(asteroids[i]);
                    alive = false;
                }
                // If top of stack is bigger positive — current one dies
                // nothing to do, just skip pushing

                // You may keep this if you want to visualize alive logic
                // if (alive) { st.push_back(asteroids[i]); }
            }
        }

        return st;
    }
};
