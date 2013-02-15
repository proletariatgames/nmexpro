import flash.Lib;
import flash.system.Capabilities;
import flash.text.TextField;
import flash.events.MouseEvent;

class ApplicationMain{
	
	function new(){
	 
		Lib.current.stage.scaleMode = flash.display.StageScaleMode.NO_SCALE;
		
		var text = new TextField();
		text.textColor = 0xFFFFFF;
		text.text = "Hello nmex!";
		text.width = 320;
		text.htmlText = "<font size='36'>Hello nmex!</font>";
		
		text.selectable = false;
		
		text.x = Capabilities.screenResolutionX/2 - text.width/2;
		text.y = Capabilities.screenResolutionY/2 - text.height/2;
		
		Lib.current.addChild(text);
		
	 	nmex.GameCenter.getInstance().authenticateLocalUser();
		
		Lib.current.stage.addEventListener(MouseEvent.CLICK, onClick);
		
		nmex.AD.showAd("a14cb4262caea88");
	}
	
	private function onClick(e:MouseEvent):Void{
		nmex.NativeUI.showAlert("nmex","Please try other APIs by yourself!");
	}
	
   #if waxe
   static public var frame : wx.Frame;
   static public var autoShowFrame : Bool = true;
   #if nme
   static public var nmeStage : wx.NMEStage;
   #end
   #end

   public static function main()
   {
      #if waxe
      wx.App.boot( function()
      {
         frame = wx.Frame.create(null,null,"Bubble Blast",null,{width: 320, height: 480 });
         #if nme
         var stage = wx.NMEStage.create(frame,null,null,{width:320,height:480});
         #end

         new ApplicationMain();
         if (autoShowFrame)
         {
            wx.App.setTopWindow(frame);
            frame.shown = true;
         }
      } );
      #else
      nme.Lib.create(
           function(){  new ApplicationMain(); },
           320, 480,
           60,
           0x000000,
             ( true   ? nme.Lib.HARDWARE  : 0) |
             ( true ? nme.Lib.RESIZABLE : 0),
          "Bubble Blast", 
          "com.mybogame.bbx2"
          
          );
       #end
   }

   public static function getAsset(inName:String):Dynamic{
      return null;
   }
}

