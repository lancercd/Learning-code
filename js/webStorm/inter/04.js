const arr = [
    {
        id: 1,
        name: 'x1'
    },
    {
        id: 2,
        name: 'x2'
    },
    {
        id: 3,
        name: 'x3',
        parentId: 2
    }
]


const tree =[
    {
        id: 1,
        name: "x1"
    },
    {
    id: 2,
    name: "x2",
    children: [
        {
            id: 3,
            name: "x3"
        }
    ]
}
]



function convertToTree(arr){
    let res = [];
    let len = arr.length;
    for (let i = 0; i < len; ++i) {
        if (!arr[i].parentId) {
            res.push(arr[i]);
        }
    }

    for (let i = 0; i < len; ++i) {
        let pid = arr[i].parentId;
        if (pid) {
            let index = res.findIndex((val, index) => {
                return val.id === pid;
            })
            if(!res[index].children){
                res[index].children = [];
            }
            res[index].children.push(arr[i]);
        }
    }
    return res;
}


console.log(convertToTree(arr));