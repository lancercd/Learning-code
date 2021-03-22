#-*- coding: UTF-8 -*-

import json
from nameko.rpc import rpc, RpcProxy


class KBQAByJiebaService ():
    name = 'logger_service'

    @rpc
    def paintService(self, request):
        print("111111111111111");
        print(request)
        res = {
	[
	{
		"experimentName": "test",
		"listExperimentID": ["cc5112c9eb299e0309d58bc86e94aedd", "ea884170064cbbcf727ddc41eea5d9f5"],
		"listMetricName": ["Accuracy", "Recall", "F_Value"],
		"listMetricValue": [["98.3", "97.3"], ["88.5", "89.5"], ["21748.85", "21750.85"]]
	}
]

}

        return res

    @rpc
    def findAllByPageService(self, request):
        print("2222222222");
        print(request)
        res = {
	"totalPage":2,
	"tableData": [
		{
			"time": "2021-01-23 22:21:05",
			"experimentName": "test",
			"experimentID": "cc5112c9eb299e0309d58bc86e94aedd",
			"parameters": "{'name': 'test', 'LearningRate' : '0.001', 'Batchsize' : '50', 'Epoches' : '20', 'NumLabels' : '2'}",
			"metric": [{"Accuracy": "98.3"}, {"Recall": "88.5"}, {"F_Value": "21748.85"}]
		},
		{
			"time": "2021-01-24 22:21:05",
			"experimentName": "test2",
			"experimentID": "ea884170064cbbcf727ddc41eea5d9f5",
			"parameters": "{'name': 'test2', 'LearningRate' : '0.002', 'Batchsize' : '51', 'Epoches' : '21', 'NumLabels' : '3'}",
			"metric": [{"Accuracy": "97.3"}, {"Recall": "89.5"}, {"F_Value": "21750.85"}]
		}
	]
}


        return res
