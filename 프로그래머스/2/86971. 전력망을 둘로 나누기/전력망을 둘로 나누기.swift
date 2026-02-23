import Foundation

func solution(_ n: Int, _ wires: [[Int]]) -> Int {
    var diffs: [Int] = []
    
    var visited: [Bool] = .init(repeating: false, count: n + 1)
    func countConnectedTowers(_ start: Int, _ seperatedWires: [Int: [Int]]) {
        if visited[start] { return }
        
        visited[start] = true
        for destNode in seperatedWires[start] ?? [] {
            countConnectedTowers(destNode, seperatedWires)
        }
    }
    
    // 하나의 전선을 뺀 새로운 전선 Dict 생성 (양방향 모두 추가)
    // 새로운 전선 Dict를 토대로 연결된 전력망 개수 세기 (분리된 전력망 개수 = n - 한쪽 전력망의 개수)
    // 한쪽 전력망 개수와 분리된 전력망 개수의 차이(절댓값)를 diffs 배열에 추가
    // diffs 배열의 최소값이 정답
    
    for i in wires.indices {
        var seperatedWires: [Int: [Int]] = [:]
        for (j, wire) in wires.enumerated() {
            if i == j { continue }
            seperatedWires[wire[0], default: []].append(wire[1])
            seperatedWires[wire[1], default: []].append(wire[0])
        }
        
        countConnectedTowers(1, seperatedWires)
        let connectedCount = visited.filter({ $0 == true }).count
        let otherConnectedCount = n - connectedCount
        diffs.append(abs(connectedCount - otherConnectedCount))
        
        visited = .init(repeating: false, count: n + 1)
    }
    
    return diffs.min()!
}