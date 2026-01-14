import Foundation

func solution(_ bridge_length: Int, _ weight: Int, _ truck_weights: [Int]) -> Int {
    
    let bridgeAllowedWeight = weight
    var truckWeightsToPass: [Int] = truck_weights
    var truckWeightsOnBridge: [Int] = []
    var trucksOnBridgeElapesd: [Int] = []
    var passedTruckWeights: [Int] = []
    
    var elapsed = 0
    let totalTruckCounts = truck_weights.count
    while passedTruckWeights.count != totalTruckCounts {
        elapsed += 1
        
        var isPassed = false
        for index in trucksOnBridgeElapesd.indices {
            trucksOnBridgeElapesd[index] += 1
            if trucksOnBridgeElapesd[index] > bridge_length {
                passedTruckWeights.append(truckWeightsOnBridge.removeFirst())
                isPassed = true
            }
        }
        if isPassed { trucksOnBridgeElapesd.removeFirst() }
        
        let trucksOnBridgeWeights = truckWeightsOnBridge.reduce(0, { $0 + $1 })
        if !truckWeightsToPass.isEmpty && (trucksOnBridgeWeights + truckWeightsToPass.first! <= bridgeAllowedWeight) {
            let truckToCross = truckWeightsToPass.removeFirst()
            truckWeightsOnBridge.append(truckToCross)
            trucksOnBridgeElapesd.append(1)
        }
    }
    
    return elapsed
}
