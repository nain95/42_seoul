# Enter your code here. Read input from STDIN. Print output to STDOUT
from collections import defaultdict


def solve():
    res = []
    j_list = list(movie_list - set(user_dic[target_user_id].keys()))
    i_list = list(user_dic[target_user_id].keys() - set(j_list))
    for j in j_list:
        c_ji = 0
        hash_j = movie_hash[j]
        sum_dev_ji = 0
        for i in i_list:
            hash_i = movie_hash[i]
            dev_ji = 0
            if len(both_assessment[hash_j][hash_i]) > 0:
                for both_id in both_assessment[hash_j][hash_i]:
                    u = user_dic[both_id]
                    dev_ji += (u[j] - u[i]) / len(both_assessment[hash_j][hash_i])
                c_ji += len(both_assessment[hash_j][hash_i])
                sum_dev_ji += (dev_ji + user_dic[target_user_id][i]) * len(both_assessment[hash_j][hash_i])
        res.append([j, round(sum_dev_ji / c_ji, 3)])
    res = sorted(res, key=lambda x:x[1], reverse=True)
    for result in res[:reco_size]:
        print(result[0], format(result[1], ".3f"))

if __name__ == "__main__":
    U, M = map(int, input().split())
    N = int(input())
    user_dic = defaultdict(dict)
    movie_list = set()
    movie_hash = defaultdict(int)
    assessment = defaultdict(int)
    both_assessment = [[[] for _ in range(M)] for _ in range(M)]
    for _ in range(N):
        user_id, movie_id, rating = map(int, input().split())
        movie_list.add(movie_id)
        assessment[movie_id] += 1
        user_dic[user_id][movie_id] = rating
    movie_num = 0
    for movie in assessment.keys():
        movie_hash[movie] = movie_num
        movie_num += 1
    for key in user_dic.keys():
        value = list(user_dic[key].keys())
        for i in range(len(value)-1):
            for j in range(i+1, len(value)):
                key_i, key_j = movie_hash[value[i]], movie_hash[value[j]]
                both_assessment[key_i][key_j].append(key)
                both_assessment[key_j][key_i].append(key)
    target_user_id = int(input())
    reco_size = int(input())
    solve()

