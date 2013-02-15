import flash.Lib;
import flash.system.Capabilities;
import flash.text.TextField;
import flash.events.MouseEvent;

class IPhoneMain{
	
	function new(){
	 
		Lib.current.stage.scaleMode = flash.display.StageScaleMode.NO_SCALE;
		
		var text = new TextField();
		text.textColor = 0x000000;
		text.text = "Hello nmex!";
		text.width = 320;
		text.htmlText = "<font size='36'>Hello nmex!</font>";
		
		text.selectable = false;
		
		text.x = Capabilities.screenResolutionX/2 - text.width/2;
		text.y = Capabilities.screenResolutionY/2 - text.height/2;
		
		Lib.current.addChild(text);
		
		
		//gamecenter
		if(Std.parseInt((nmex.Device.osVersion().split(".")[0])) >= 4){
		 	nmex.GameCenter.getInstance().authenticateLocalUser();
		}
		
		Lib.current.stage.addEventListener(MouseEvent.CLICK, onClick);
				
	}
	
	private function onClick(e:MouseEvent):Void{
		nmex.NativeUI.showAlert("nmex","Please try other APIs by yourself!");
	}

	
	public static function main (){
 		var w = 320;
 		var h = 480;
 		var fps = 60;
 		var bgColor = 0xffffff;
 		var flags = 
 		     nme.Lib.FULLSCREEN |
 		     nme.Lib.BORDERLESS |
 		     nme.Lib.RESIZABLE  |
 		     nme.Lib.HARDWARE   |
 		     nme.Lib.VSYNC      |
 		     0;
 		var name = "iPhone Application";
 		
 		
 		nme.Lib.create(function(){new IPhoneMain();},w,h,fps,bgColor,flags, name);
	}

}
   

