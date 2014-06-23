var tab = (function(oFBParam,oFB){
	return {
		snsPost : function(snsType){
			if(typeof snsType === 'string'){
				switch(snsType){
					case 'Facebook' :
						//페이스북 공유하기
						oFB.snsPost(sns.facebook[0]);
						break;
					case 'Twitter' :
						//트위터 공유하기
						var msg = sns.twitter.msg;
                        var url = sns.twitter.url;
						window.open('http://twitter.com/intent/tweet?text='+encodeURIComponent(msg)+'&url='+encodeURIComponent(url),'_twitter');
						break;
					case 'KakaoTalk' :
						//카카오톡 공유하기
						 kakao.link("talk").send(sns.kakaoTalk[0]);
						break;
					case 'KakaoStory' :
						//카카오스토리 공유하기
						kakao.link("story").send(sns.kakaoStory[0]);
						break;
					default : 
						alert('sns타입확인해주세요.');
						break;
				}
			}
		},
		setAuth : function(callback){
			oFB.getAuthCheck(function(res){
				switch(res.status){
					//권한이 없을 경우
					case 'unknown':
					case 'not_authorized':
						FB.login(function(res){
							
							//취소 눌렀을 경우
							if(res.authResponse == null){
								
							}else{
								
								sAccessToken = res.authResponse.accessToken;
								sUID = res.authResponse.userID;
								setUSerInfo(function(r){
									return callback(r);
								});
							}
						},{scope:oFBParam.perms});
						break;
					//권한이 있을경우
					case 'connected':
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
		}
	}
	
	
})(oFBParam,oFB);