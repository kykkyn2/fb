var c = window.console;
//사용자 정보를 담을 객체
var userINFO = {
    'useruid' : '',
    'name' : '',
    'username' : '',
    'link' : '',
    'gender' : '',
    'user_photo_url' : '',
    'device':''
}

//사용자 정보를 호출하여 userINFO에 담는다.
var setUSerInfo = function(callback){
    userINFO.useruid = FB.getUserID(); //사용자 FB UID
        
    FB.api("/me", function(res) {
        
        userINFO.name = res.name; //사용자 이름
        userINFO.username = res.username; //사용자 페이스북 이름
        userINFO.link = res.link; //사용자 페이스북 주소
        userINFO.gender = res.gender; //사용자 성별
        userINFO.user_photo_url = 'https://graph.facebook.com/'+res.id+'/picture';//사용자 프로필 이미지
        userINFO.device = oFBParam.type;
        
        userDataInsert( function (rv) {
        	
        	if ( rv == 'whiteSpace' ) {
        		alert('Facebook Data를 가지고 오지 못했습니다.');
				top.location.reload();
        	} else {
        		return callback(rv);
        	}
        	
        } );
        
    });
}

//사용자 정보 DB에 저장
var userDataInsert = function(cb){
	//userINFO.username = "";
	if ( userINFO.useruid == '' || userINFO.username == '') {
		return cb('whiteSpace');
	} else {
		$.ajax({
	        type : "POST",
	        url : "ajax/ajax.php",
	        data : {
	            param : userINFO, //사용자 정보가 담겨 있는 객체
	            type : "userInfoInsert" // 타입
	        },
	        success : function(resultText) {
	            
	            var resultData = $.parseJSON(resultText); //결과값을 JSON 형으로 파싱
	            
	            if(resultData.status == "200"){ //정상적으로 DB에 저장이 됐을 경우
	            	return cb(resultData);
	            } else {
	            	return cb(resultData);
	            }
	        }
	    }); 
	}
}

/*ajax처리*/
function _ajax(oParam, fnCallback) {
    if( typeof oParam === "string") {
        oParam = jQuery.parseJSON(oParam);
    }
    $.ajax({
        url : oParam.url,
        data : oParam.data,
        type : "POST",
        success : function(res) {
            if( typeof res === "string") {
                res = jQuery.parseJSON(res);
            }
            fnCallback(res);
        },
        error : function(res) {
            if( typeof res === "string") {
                res = jQuery.parseJSON(res);
            }
        }
    });
}