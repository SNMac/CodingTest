import Foundation

func solution(_ progresses: [Int], _ speeds: [Int]) -> [Int] {
    
    var inProgressArr: [Int] = progresses
    var etaArr: [Int] = []
    for (index, progress) in inProgressArr.enumerated() {
        let eta: Double = Double(100 - progress) / (Double)(speeds[index])
        etaArr.append(Int(eta.rounded(.up)))
    }
    
    var deployment: [Int] = []
    while !etaArr.isEmpty {
        let first = etaArr.first!
        etaArr.remove(at: 0)
        etaArr = etaArr.map { $0 - first }
        
        var deploy = 1
        while !etaArr.isEmpty && etaArr.first! <= 0 {
            deploy += 1
            etaArr.removeFirst()
        }
        deployment.append(deploy)
    }
    
    return deployment
}
