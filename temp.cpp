/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:02:05 by obelaizi          #+#    #+#             */
/*   Updated: 2023/03/16 19:05:56 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include               <iostream>
# include               <algorithm>
# include				<iterator>
# include               <vector>
# include               <string>
# include               <map>
# include               <unordered_map>
# include               <set>
# include               <unordered_set>
# include               <bitset>
# include               <queue>
# include               <stack>
# include               <complex>
# include               <cmath>
# include               <climits>
# include               <cstring>
 
# define 	prnt_int 			copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
# define    ll          long long
# define    ull         unsigned long long
 
using namespace std;
 
 
ull     fact(ull n)
{
    ull res = 1;
    
    while (n--) res *= (n + 1);
    return (res);
}
 
 
 
int get_max (int x1, int x2, int x3)
{
	if (x1 > x2 && x1 > x3)
		return (x1);
	else if (x2 > 1 && x2 > x3)
		return (x2);
	else
		return (x3);
}
 
 
int get_min (int x1, int x2, int x3)
{
	if (x1 < x2 && x1 < x3)
		return (x1);
	else if (x2 < 1 && x2 < x3)
		return (x2);
	else
		return (x3);
}

void    solve()
{

}

int func(int i)
{
	if (i % 2 == 0)
		return 1;
	return 0;
}
int main()
{
    int     cases;
    cin >> cases;
    while (cases--) solve();
    return (0);	    
}