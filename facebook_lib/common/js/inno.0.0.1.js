(function( oFBParam , oFB , snsParam){
	
	fbAuth = function( callback ){
		oFB.getAuthCheck(function(res){
			console.log(res.status);
			switch(res.status){
				//권한이 없을 경우
				case 'unknown':
				case 'not_authorized':
					FB.login(function(res){
						//취소 눌렀을 경우
						if(res.authResponse == null){
							
						}else{
							console.log("===========");
							console.log(res);
							sAccessToken = res.authResponse.accessToken;
							sUID = res.authResponse.userID;
							setUSerInfo(function(r){
								return callback(r);
							});
						}
					},{scope:oFBParam.perms,return_scopes:true});
					break;
				//권한이 있을경우
				case 'connected':
					console.log("connected됨");
					console.log(res);
					sAccessToken = res.authResponse.accessToken;
					sUID = res.authResponse.userID;
					setUSerInfo(function(r){
						return callback(r);
					});
					break;
					
				default : 
					break;
			}
		});
	},
	
	snsShare = function( snsType , callback ){
		
		switch( snsType ){
			case 'fb' :
				//페이스북 공유하기
				var publish = {
					method: 'feed',
                    link: oFBParam.appsUrl,
                    name: snsParam.name,
                    picture: snsParam.picture,
                    caption: snsParam.caption,
                    description : '<center></center>'
				}
				FB.ui( publish ,function( res ){
					return callback(res);
				});
				
				break;
			case 'tw' :
				//트위터 공유하기
				var msg = snsParam.tw_msg;
                var url = snsParam.tw_url;
				window.open('http://twitter.com/intent/tweet?text='+encodeURIComponent(msg)+'&url='+encodeURIComponent(url),'_twitter');
				break;
			case 'kt' :
				//카카오톡 공유하기
				
				kakao.link("talk").send({
					"msg" : snsParam.msg ,
				    "url" : snsParam.url ,  
				    "appid" : snsParam.appid ,
				    "appver" : "2.0",		//고정값
				    "appname" : snsParam.appname ,
				    "type" : "link"			//고정값
				});
				
				//kakao.link("talk").send(sns.kakaoTalk[0]);
				break;
			case 'ks' :
				//카카오스토리 공유하기
				kakao.link("story").send({
					post : snsParam.post ,
				    appid : oFBParam.appsUrl ,
				    appver : "1.0",
				    appname : snsParam.appname ,
				    urlinfo : JSON.stringify({
					title: snsParam.title ,
						desc: snsParam.desc ,
						imageurl:[ snsParam.imageurl ],
						type:"website"})
				});
				break;
			default : 
				alert('sns타입확인해주세요.');
				break;
		}
	}
	
	
	
	
})( oFBParam , oFB , snsParam);