This is a branch of the NMEX library available here: http://code.google.com/p/nmex/

Features added:
* Fixed build for latest version of NME (3.5.5)
* Added support for local multiplayer via Game Center
* Added local notifications (iOS)
* AudioSession class for tracking iPod player state, and controlling app audio behavior
* Improved text in iRate
* Various bug fixes

Android support is untested currently.

_Installation_

1. Install NMEX into a directory:
git clone https://github.com/proletariatgames/nmexpro.git DESTINATION-FOLDER
2. Point haxelib to this directory:
haxelib dev nmex DESTINATION-FOLDER
3. Add the following to your application NMML file:<br />
  &lt;haxelib name="nmex" if="ios" /&gt;
4. You may need to add the following framework dependencies:<br />
  &lt;dependency name="GameKit.framework" if="ios" /&gt;<br />
  &lt;dependency name="StoreKit.framework" if="ios" /&gt;<br />
  &lt;dependency name="SystemConfiguration.framework" if="ios" /&gt;<br />
  &lt;dependency name="Social.framework" if="ios" /&gt;<br />
  &lt;dependency name="Accounts.framework" if="ios" /&gt;<br />
  &lt;dependency name="AdSupport.framework" if="ios" /&gt;<br />
  &lt;dependency name="MediaPlayer.framework" if="ios" /&gt;<br />
