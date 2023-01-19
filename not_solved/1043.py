N, M = input().split()
N = int(N)
M = int(M)

know_truth = input().split()
know_truth = [int(i) for i in know_truth[1:]]
edge_info = {}
party_graph = {}

for p_num in range(M):
    party_info = input().split()
    num_people = int(party_info[0])
    party_people = [int(i) for i in party_info[1:]]

    party_graph[p_num] = party_people

    

    # 진실을 아는 자가 오늘의 파뤼피인가?
    for truth_knower in know_truth:


    for i, person in enumerate(party_people):
        if not person in edge_info.keys():
            edge_info[person] = []

        edge_info[person].extend(party_info[:i])
        edge_info[person].extend(party_info[i+1:])

print(edge_info)