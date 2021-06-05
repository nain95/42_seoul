# Enter your code here. Read input from STDIN. Print output to STDOUT

# Enter your code here. Read input from STDIN. Print output to STDOUT
from collections import defaultdict

def cnt_like_or_dislick(assessment, i, avg):
    res = [0, 0] #[like_cnt, dislike_cnt]
    for both_id in assessment:
        if user_dic[both_id][i] > avg:
            res[0] += 1
        else:
            res[1] += 1
    return res
    

def solve():
    ans = []
    j_list = list(movie_list - set(user_dic[target_user_id].keys()))
    i_list = list(user_dic[target_user_id].keys() - set(j_list))
    for j in j_list:
        like_c_ji = 0
        dislike_c_ji = 0
        like_sum_dev_ji = 0
        dislike_sum_dev_ji = 0
        hash_j = movie_hash[j]
        for i in i_list:
            hash_i = movie_hash[i]
            like_dev_ji = 0
            dislike_dev_ji = 0
            if len(both_assessment[hash_j][hash_i]) > 0:
                for both_id in both_assessment[hash_j][hash_i]:
                    u = user_dic[both_id]
                    avg = sum(u.values()) / len(u.values())
                    like_cnt, dislike_cnt = cnt_like_or_dislick(both_assessment[hash_j][hash_i], i, avg)
                    if u[i] > avg:
                        like_dev_ji += (u[j] - u[i]) / like_cnt
                    else:
                        dislike_dev_ji += (u[j] - u[i]) / dislike_cnt
                if u[i] > avg:
                    like_c_ji += like_cnt
                    like_sum_dev_ji += (like_dev_ji + user_dic[target_user_id][i]) * like_cnt
                else:
                    dislike_c_ji += dislike_cnt
                    dislike_sum_dev_ji += (dislike_dev_ji + user_dic[target_user_id][i]) * dislike_cnt
        ans.append([j, round((like_sum_dev_ji + dislike_sum_dev_ji) / (like_c_ji + dislike_c_ji), 3)])
    ans = sorted(ans, key=lambda x:x[1], reverse=True)
    for result in ans[:reco_size]:
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

