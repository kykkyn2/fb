var sns = {
	//페이스북 공유하기
	"facebook":[{
			"mediaType" : 'image'
			,"title" : '눈물 뚝! Smile Again!'
			,"imgSrc" : oFBParam.SHARE_IMAGE_URL
			,"imgLink" : oFBParam.appsUrl
			,"caption" :'웃음을 찾기 위한 신년 프로젝트! 2013년에 나는 얼마나 울었을까? AIA생명에서 페이스북을 분석하고, 2014년에는 Real Smile Never Stops!'
			,"publishMsg" :''
	}],
	//트위터 멘션
	"twitter":{
		"msg" : "웃음을 찾기 위한 신년 프로젝트! AIA생명에서 페이스북을 분석하고, Sony 카메라의 주인공에 도전하세요! 2014년에는 Real Smile Never Stops! #AIA생명 >>"
		,"url" : oFBParam.appsUrl
	},
	//카카오 스토리	
	"kakaoStory":[{
			"post" : '여러분 제 응원 영상 보고 힘내세요.♥ 마음에 들었다면 좋아요 눌러주는 센스! >> http://apps.facebook.com/hanaucc'
			,"appid" : 'http://dev.innobirds.com/jhpark/AIA/tear'
			,"appver" : '2.0'	//고정값
			,"appname" : 'AIA생명'
			,"urlinfo" : JSON.stringify({title:"눈물 뚝! Smile Again!",
				desc:"웃음을 찾기 위한 신년 프로젝트! 2013년에 나는 얼마나 울었을까? AIA생명에서 페이스북을 분석하고, 2014년에는 Real Smile Never Stops!",
				imageurl:[oFBParam.SHARE_IMAGE_URL],
				type:"website"})
	}],
	//카카오톡
	"kakaoTalk" : [{
		"msg" : "웃음을 찾기 위한 신년 프로젝트! AIA생명에서 페이스북을 분석하고, Sony 카메라의 주인공에 도전하세요! 2014년에는 Real Smile Never Stops!",
	    "url" : "http://link.kakao.com",  
	    "appid" : "http://dev.innobirds.com/jhpark/AIA/tear",
	    "appver" : "2.0",		//고정값
	    "appname" : "눈물 뚝! Smile Again!",
	    "type" : "link"			//고정값
	}]
};
