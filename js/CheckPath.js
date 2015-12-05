
function getPathfileList(){
    var array[];
    var folder = new Folder ("./libpath/");
    var fileList = folder.getFiles();
    for (var i=0; i<fileList.length; i++){
        var str = fileList[i].fullName;
        if (str.match(ew RegExp("\.so$", ""))){
            array.push(str);
        }
    }
    return array;
}

