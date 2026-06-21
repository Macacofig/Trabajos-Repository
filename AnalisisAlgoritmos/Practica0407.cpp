#include <iostream>
#include <vector>
#include <stack>
using namespace std;


int main()
{
	int n;
	cin >> n;
	string cadena;
	bool valido;
	while (n--)
	{
		cin >> cadena;
		stack<char> pila;
		valido = true;
		for (char c : cadena)
		{
			if (c == '(' || c == '[')
			{
				pila.push(c);
			}
			else
			{
				if (c == ')')
				{
					if (pila.empty() || pila.top() != '(')
					{
						valido = false;
						break;
					}
				}
				else
				{
					if (pila.empty() || pila.top() != '[')
					{
						valido = false;
						break;
					}
				}
				pila.pop();
			}
		}
		if (valido)
		{
			cout << "Yes\n";
		}
		else
		{
			cout << "No\n";
		}
	}
}
/*

const int MOD = 1e9 + 7;

int main() {
	int n;
	cin >> n;

	vector<int> dp(n + 1, 0);
	dp[0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 6; j++) {
			if (i - j >= 0) {
				dp[i] = (dp[i] + dp[i - j]) % MOD;
			}
		}
	}

	cout << dp[n] << "\n";
}

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	set<int> s;

	int l = 0, ans = 0;

	for (int r = 0; r < n; r++) {
		while (s.count(a[r])) {
			s.erase(a[l]);
			l++;
		}

		s.insert(a[r]);
		ans = max(ans, r - l + 1);
	}

	cout << ans << "\n";
}

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

using ll = long long;

string s;
ll dp[20][11][2][2];
// pos, last_digit (0-9, 10 = none), tight, leading_zero

ll solve(int pos, int last, bool tight, bool leading_zero) {
	if (pos == (int)s.size()) return 1;

	ll& res = dp[pos][last][tight][leading_zero];
	if (res != -1) return res;

	res = 0;
	int limit = tight ? (s[pos] - '0') : 9;

	for (int d = 0; d <= limit; d++) {
		bool new_tight = tight && (d == limit);
		bool new_leading = leading_zero && (d == 0);

		if (!new_leading && d == last) continue;

		int new_last = new_leading ? 10 : d;

		res += solve(pos + 1, new_last, new_tight, new_leading);
	}

	return res;
}

ll f(ll x) {
	if (x < 0) return 0;
	s = to_string(x);
	memset(dp, -1, sizeof(dp));
	return solve(0, 10, 1, 1);
}

int main() {
	ll a, b;
	cin >> a >> b;

	cout << f(b) - f(a - 1) << "\n";
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	vector<int> a(n + 1), b(m + 1);

	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int j = 1; j <= m; j++) cin >> b[j];

	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

	// construir DP
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i] == b[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	// reconstrucción
	int i = n, j = m;
	vector<int> ans;

	while (i > 0 && j > 0) {
		if (a[i] == b[j]) {
			ans.push_back(a[i]);
			i--; j--;
		}
		else if (dp[i - 1][j] > dp[i][j - 1]) {
			i--;
		}
		else {
			j--;
		}
	}

	reverse(ans.begin(), ans.end());

	// salida
	cout << dp[n][m] << "\n";
	for (int x : ans) cout << x << " ";
	cout << "\n";

	return 0;
}
/*
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	long long x, current, best;

	cin >> x;
	current = best = x;

	for (int i = 1; i < n; i++) {
		cin >> x;
		current = max(x, current + x);
		best = max(best, current);
	}

	cout << best << "\n";

	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<pair<int, int>> events;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		events.push_back({ a, 1 });   // llegada
		events.push_back({ b, -1 });  // salida
	}

	sort(events.begin(), events.end());

	int current = 0, maxCustomers = 0;

	for (auto& e : events) {
		current += e.second;
		maxCustomers = max(maxCustomers, current);
	}

	cout << maxCustomers << "\n";

	return 0;
}

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> solutions;
vector<int> board(8);

bool isSafe(int col, int row) {
	for (int i = 0; i < col; i++) {
		if (board[i] == row || abs(board[i] - row) == abs(i - col))
			return false;
	}
	return true;
}

void generate(int col) {
	if (col == 8) {
		solutions.push_back(board);
		return;
	}
	for (int row = 1; row <= 8; row++) {
		if (isSafe(col, row)) {
			board[col] = row;
			generate(col + 1);
		}
	}
}

int main() {

	// Generar todas las soluciones válidas
	generate(0);

	vector<int> input(8);
	int caseNo = 1;

	while (cin >> input[0]) {
		for (int i = 1; i < 8; i++)
			cin >> input[i];

		int ans = 8; // máximo posible

		for (auto& sol : solutions) {
			int moves = 0;
			for (int i = 0; i < 8; i++) {
				if (sol[i] != input[i])
					moves++;
			}
			ans = min(ans, moves);
		}

		cout << "Case " << caseNo++ << ": " << ans << "\n";
	}

	return 0;
}

#include <string>
void ejer2(std::string formatoNormal)
{
	std::string hora = formatoNormal.substr(0, 2);
	std::string resto = formatoNormal.substr(2, formatoNormal.size() - 4);
	std::string resto2 = formatoNormal.substr(0, formatoNormal.size() - 2);
	std::string PMAM = formatoNormal.substr(formatoNormal.size() - 2, 2);
	int horaNum = stoi(hora);
	std::string res;
	if (PMAM == "PM")
	{
		horaNum += 12;
		res = std::to_string(horaNum);
	}
	if(PMAM == "AM" && horaNum == 12)
	{
		res = "00";
	}
	if (res != "")
	{
		std::cout << res + resto;
	}
	else
	{
		std::cout << resto2;
	}
}
int main()
{
	std::string cadena;
	std::cin >> cadena;
	ejer2("01:01:00PM");
}





void ejer1(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (j < n - i)
			{
				std::cout << " ";
			}
			else
			{
				std::cout << "#";
			}
		}
		std::cout << std::endl;
	}
}
int main()
{
	int n;
	std::cin >> n;
	ejer1(n);
}
*/
