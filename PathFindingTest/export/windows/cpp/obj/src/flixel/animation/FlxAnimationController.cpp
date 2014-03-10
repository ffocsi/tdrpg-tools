#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_FlxObject
#include <flixel/FlxObject.h>
#endif
#ifndef INCLUDED_flixel_FlxSprite
#include <flixel/FlxSprite.h>
#endif
#ifndef INCLUDED_flixel_animation_FlxAnimation
#include <flixel/animation/FlxAnimation.h>
#endif
#ifndef INCLUDED_flixel_animation_FlxAnimationController
#include <flixel/animation/FlxAnimationController.h>
#endif
#ifndef INCLUDED_flixel_animation_FlxBaseAnimation
#include <flixel/animation/FlxBaseAnimation.h>
#endif
#ifndef INCLUDED_flixel_animation_FlxPrerotatedAnimation
#include <flixel/animation/FlxPrerotatedAnimation.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_system_debug_LogStyle
#include <flixel/system/debug/LogStyle.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_LogFrontEnd
#include <flixel/system/frontEnds/LogFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_system_layer_frames_FlxFrame
#include <flixel/system/layer/frames/FlxFrame.h>
#endif
#ifndef INCLUDED_flixel_system_layer_frames_FlxSpriteFrames
#include <flixel/system/layer/frames/FlxSpriteFrames.h>
#endif
#ifndef INCLUDED_flixel_util_FlxArrayUtil
#include <flixel/util/FlxArrayUtil.h>
#endif
#ifndef INCLUDED_flixel_util_FlxRandom
#include <flixel/util/FlxRandom.h>
#endif
#ifndef INCLUDED_flixel_util_loaders_CachedGraphics
#include <flixel/util/loaders/CachedGraphics.h>
#endif
#ifndef INCLUDED_flixel_util_loaders_TexturePackerData
#include <flixel/util/loaders/TexturePackerData.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
namespace flixel{
namespace animation{

Void FlxAnimationController_obj::__construct(::flixel::FlxSprite Sprite)
{
HX_STACK_FRAME("flixel.animation.FlxAnimationController","new",0x0b6477fc,"flixel.animation.FlxAnimationController.new","flixel/animation/FlxAnimationController.hx",11,0xa6f01372)

HX_STACK_ARG(Sprite,"Sprite")
{
	HX_STACK_LINE(21)
	this->frameIndex = (int)0;
	HX_STACK_LINE(80)
	this->_sprite = Sprite;
	HX_STACK_LINE(81)
	this->_animations = ::haxe::ds::StringMap_obj::__new();
}
;
	return null();
}

//FlxAnimationController_obj::~FlxAnimationController_obj() { }

Dynamic FlxAnimationController_obj::__CreateEmpty() { return  new FlxAnimationController_obj; }
hx::ObjectPtr< FlxAnimationController_obj > FlxAnimationController_obj::__new(::flixel::FlxSprite Sprite)
{  hx::ObjectPtr< FlxAnimationController_obj > result = new FlxAnimationController_obj();
	result->__construct(Sprite);
	return result;}

Dynamic FlxAnimationController_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxAnimationController_obj > result = new FlxAnimationController_obj();
	result->__construct(inArgs[0]);
	return result;}

hx::Object *FlxAnimationController_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::flixel::interfaces::IFlxDestroyable_obj)) return operator ::flixel::interfaces::IFlxDestroyable_obj *();
	return super::__ToInterface(inType);
}

Void FlxAnimationController_obj::update( ){
{
		HX_STACK_FRAME("flixel.animation.FlxAnimationController","update",0x8fb487ed,"flixel.animation.FlxAnimationController.update","flixel/animation/FlxAnimationController.hx",86,0xa6f01372)
		HX_STACK_THIS(this)
		HX_STACK_LINE(86)
		if (((this->_curAnim != null()))){
			HX_STACK_LINE(88)
			this->_curAnim->update();
		}
		else{
			HX_STACK_LINE(90)
			if (((this->_prerotated != null()))){
				HX_STACK_LINE(92)
				this->_prerotated->set_angle(this->_sprite->angle);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxAnimationController_obj,update,(void))

::flixel::animation::FlxAnimationController FlxAnimationController_obj::copyFrom( ::flixel::animation::FlxAnimationController controller){
	HX_STACK_FRAME("flixel.animation.FlxAnimationController","copyFrom",0x9c3f4ea3,"flixel.animation.FlxAnimationController.copyFrom","flixel/animation/FlxAnimationController.hx",97,0xa6f01372)
	HX_STACK_THIS(this)
	HX_STACK_ARG(controller,"controller")
	HX_STACK_LINE(98)
	this->destroyAnimations();
	HX_STACK_LINE(100)
	for(::cpp::FastIterator_obj< ::flixel::animation::FlxAnimation > *__it = ::cpp::CreateFastIterator< ::flixel::animation::FlxAnimation >(controller->_animations->iterator());  __it->hasNext(); ){
		::flixel::animation::FlxAnimation anim = __it->next();
		this->add(anim->name,anim->_frames,anim->frameRate,anim->looped);
	}
	HX_STACK_LINE(105)
	if (((controller->_prerotated != null()))){
		HX_STACK_LINE(107)
		this->createPrerotated(null());
	}
	HX_STACK_LINE(110)
	if (((controller->get_name() != null()))){
		HX_STACK_LINE(112)
		this->set_name(controller->get_name());
	}
	HX_STACK_LINE(115)
	this->set_frameIndex(controller->frameIndex);
	HX_STACK_LINE(117)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(FlxAnimationController_obj,copyFrom,return )

Void FlxAnimationController_obj::createPrerotated( ::flixel::animation::FlxAnimationController Controller){
{
		HX_STACK_FRAME("flixel.animation.FlxAnimationController","createPrerotated",0xc538c8e6,"flixel.animation.FlxAnimationController.createPrerotated","flixel/animation/FlxAnimationController.hx",121,0xa6f01372)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Controller,"Controller")
		HX_STACK_LINE(122)
		this->destroyAnimations();
		HX_STACK_LINE(123)
		if (((Controller != null()))){
			HX_STACK_LINE(123)
			Controller = Controller;
		}
		else{
			HX_STACK_LINE(123)
			Controller = hx::ObjectPtr<OBJ_>(this);
		}
		HX_STACK_LINE(124)
		this->_prerotated = ::flixel::animation::FlxPrerotatedAnimation_obj::__new(Controller,Controller->_sprite->bakedRotationAngle);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxAnimationController_obj,createPrerotated,(void))

Void FlxAnimationController_obj::destroyAnimations( ){
{
		HX_STACK_FRAME("flixel.animation.FlxAnimationController","destroyAnimations",0x0b136325,"flixel.animation.FlxAnimationController.destroyAnimations","flixel/animation/FlxAnimationController.hx",128,0xa6f01372)
		HX_STACK_THIS(this)
		HX_STACK_LINE(129)
		this->clearAnimations();
		HX_STACK_LINE(130)
		this->clearPrerotated();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxAnimationController_obj,destroyAnimations,(void))

Void FlxAnimationController_obj::destroy( ){
{
		HX_STACK_FRAME("flixel.animation.FlxAnimationController","destroy",0xb4f8d296,"flixel.animation.FlxAnimationController.destroy","flixel/animation/FlxAnimationController.hx",134,0xa6f01372)
		HX_STACK_THIS(this)
		HX_STACK_LINE(135)
		this->destroyAnimations();
		HX_STACK_LINE(136)
		this->_animations = null();
		HX_STACK_LINE(137)
		this->callback = null();
		HX_STACK_LINE(138)
		this->_sprite = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxAnimationController_obj,destroy,(void))

Void FlxAnimationController_obj::clearPrerotated( ){
{
		HX_STACK_FRAME("flixel.animation.FlxAnimationController","clearPrerotated",0x8ef9ed6f,"flixel.animation.FlxAnimationController.clearPrerotated","flixel/animation/FlxAnimationController.hx",142,0xa6f01372)
		HX_STACK_THIS(this)
		HX_STACK_LINE(143)
		if (((this->_prerotated != null()))){
			HX_STACK_LINE(145)
			this->_prerotated->destroy();
		}
		HX_STACK_LINE(147)
		this->_prerotated = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxAnimationController_obj,clearPrerotated,(void))

Void FlxAnimationController_obj::clearAnimations( ){
{
		HX_STACK_FRAME("flixel.animation.FlxAnimationController","clearAnimations",0x7ffc9e78,"flixel.animation.FlxAnimationController.clearAnimations","flixel/animation/FlxAnimationController.hx",151,0xa6f01372)
		HX_STACK_THIS(this)
		HX_STACK_LINE(152)
		if (((this->_animations != null()))){
			HX_STACK_LINE(154)
			::flixel::animation::FlxAnimation anim;		HX_STACK_VAR(anim,"anim");
			HX_STACK_LINE(155)
			for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(this->_animations->keys());  __it->hasNext(); ){
				::String key = __it->next();
				{
					HX_STACK_LINE(157)
					anim = this->_animations->get(key);
					HX_STACK_LINE(158)
					if (((anim != null()))){
						HX_STACK_LINE(160)
						anim->destroy();
					}
					HX_STACK_LINE(162)
					this->_animations->remove(key);
				}
;
			}
		}
		HX_STACK_LINE(165)
		this->_curAnim = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxAnimationController_obj,clearAnimations,(void))

::flixel::animation::FlxAnimation FlxAnimationController_obj::get( ::String Name){
	HX_STACK_FRAME("flixel.animation.FlxAnimationController","get",0x0b5f2832,"flixel.animation.FlxAnimationController.get","flixel/animation/FlxAnimationController.hx",175,0xa6f01372)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Name,"Name")
	HX_STACK_LINE(175)
	return this->_animations->get(Name);
}


HX_DEFINE_DYNAMIC_FUNC1(FlxAnimationController_obj,get,return )

Void FlxAnimationController_obj::add( ::String Name,Array< int > Frames,hx::Null< int >  __o_FrameRate,hx::Null< bool >  __o_Looped){
int FrameRate = __o_FrameRate.Default(30);
bool Looped = __o_Looped.Default(true);
	HX_STACK_FRAME("flixel.animation.FlxAnimationController","add",0x0b5a99bd,"flixel.animation.FlxAnimationController.add","flixel/animation/FlxAnimationController.hx",186,0xa6f01372)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Name,"Name")
	HX_STACK_ARG(Frames,"Frames")
	HX_STACK_ARG(FrameRate,"FrameRate")
	HX_STACK_ARG(Looped,"Looped")
{
		HX_STACK_LINE(188)
		int numFrames = (Frames->length - (int)1);		HX_STACK_VAR(numFrames,"numFrames");
		HX_STACK_LINE(189)
		int i = numFrames;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(190)
		while(((i >= (int)0))){
			HX_STACK_LINE(192)
			if (((Frames->__get(i) >= this->_sprite->frames))){
				HX_STACK_LINE(194)
				Frames->splice(i,(int)1);
			}
			HX_STACK_LINE(196)
			(i)--;
		}
		HX_STACK_LINE(199)
		if (((Frames->length > (int)0))){
			HX_STACK_LINE(201)
			::flixel::animation::FlxAnimation anim = ::flixel::animation::FlxAnimation_obj::__new(hx::ObjectPtr<OBJ_>(this),Name,Frames,FrameRate,Looped);		HX_STACK_VAR(anim,"anim");
			HX_STACK_LINE(202)
			this->_animations->set(Name,anim);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(FlxAnimationController_obj,add,(void))

Void FlxAnimationController_obj::addByNames( ::String Name,Array< ::String > FrameNames,hx::Null< int >  __o_FrameRate,hx::Null< bool >  __o_Looped){
int FrameRate = __o_FrameRate.Default(30);
bool Looped = __o_Looped.Default(true);
	HX_STACK_FRAME("flixel.animation.FlxAnimationController","addByNames",0x17c20e34,"flixel.animation.FlxAnimationController.addByNames","flixel/animation/FlxAnimationController.hx",215,0xa6f01372)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Name,"Name")
	HX_STACK_ARG(FrameNames,"FrameNames")
	HX_STACK_ARG(FrameRate,"FrameRate")
	HX_STACK_ARG(Looped,"Looped")
{
		HX_STACK_LINE(215)
		if (((bool((this->_sprite->cachedGraphics != null())) && bool((this->_sprite->cachedGraphics->data != null()))))){
			HX_STACK_LINE(217)
			Array< int > indices = Array_obj< int >::__new();		HX_STACK_VAR(indices,"indices");
			HX_STACK_LINE(218)
			int l = FrameNames->length;		HX_STACK_VAR(l,"l");
			HX_STACK_LINE(219)
			{
				HX_STACK_LINE(219)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(219)
				while(((_g < l))){
					HX_STACK_LINE(219)
					int i = (_g)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(221)
					::String name = FrameNames->__get(i);		HX_STACK_VAR(name,"name");
					HX_STACK_LINE(222)
					if ((this->_sprite->framesData->framesHash->exists(name))){
						HX_STACK_LINE(224)
						::flixel::system::layer::frames::FlxFrame frameToAdd = this->_sprite->framesData->framesHash->get(name);		HX_STACK_VAR(frameToAdd,"frameToAdd");
						HX_STACK_LINE(225)
						indices->push(::flixel::util::FlxArrayUtil_obj::indexOf_flixel_system_layer_frames_FlxFrame(this->_sprite->framesData->frames,frameToAdd,null()));
					}
				}
			}
			HX_STACK_LINE(229)
			if (((indices->length > (int)0))){
				HX_STACK_LINE(231)
				::flixel::animation::FlxAnimation anim = ::flixel::animation::FlxAnimation_obj::__new(hx::ObjectPtr<OBJ_>(this),Name,indices,FrameRate,Looped);		HX_STACK_VAR(anim,"anim");
				HX_STACK_LINE(232)
				this->_animations->set(Name,anim);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(FlxAnimationController_obj,addByNames,(void))

Void FlxAnimationController_obj::addByStringIndicies( ::String Name,::String Prefix,Array< ::String > Indicies,::String Postfix,hx::Null< int >  __o_FrameRate,hx::Null< bool >  __o_Looped){
int FrameRate = __o_FrameRate.Default(30);
bool Looped = __o_Looped.Default(true);
	HX_STACK_FRAME("flixel.animation.FlxAnimationController","addByStringIndicies",0x465aea43,"flixel.animation.FlxAnimationController.addByStringIndicies","flixel/animation/FlxAnimationController.hx",248,0xa6f01372)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Name,"Name")
	HX_STACK_ARG(Prefix,"Prefix")
	HX_STACK_ARG(Indicies,"Indicies")
	HX_STACK_ARG(Postfix,"Postfix")
	HX_STACK_ARG(FrameRate,"FrameRate")
	HX_STACK_ARG(Looped,"Looped")
{
		HX_STACK_LINE(248)
		if (((bool((this->_sprite->cachedGraphics != null())) && bool((this->_sprite->cachedGraphics->data != null()))))){
			HX_STACK_LINE(250)
			Array< int > frameIndices = Array_obj< int >::__new();		HX_STACK_VAR(frameIndices,"frameIndices");
			HX_STACK_LINE(251)
			int l = Indicies->length;		HX_STACK_VAR(l,"l");
			HX_STACK_LINE(252)
			{
				HX_STACK_LINE(252)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(252)
				while(((_g < l))){
					HX_STACK_LINE(252)
					int i = (_g)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(254)
					::String name = ((Prefix + Indicies->__get(i)) + Postfix);		HX_STACK_VAR(name,"name");
					HX_STACK_LINE(255)
					if ((this->_sprite->framesData->framesHash->exists(name))){
						HX_STACK_LINE(257)
						::flixel::system::layer::frames::FlxFrame frameToAdd = this->_sprite->framesData->framesHash->get(name);		HX_STACK_VAR(frameToAdd,"frameToAdd");
						HX_STACK_LINE(258)
						frameIndices->push(::flixel::util::FlxArrayUtil_obj::indexOf_flixel_system_layer_frames_FlxFrame(this->_sprite->framesData->frames,frameToAdd,null()));
					}
				}
			}
			HX_STACK_LINE(262)
			if (((frameIndices->length > (int)0))){
				HX_STACK_LINE(264)
				::flixel::animation::FlxAnimation anim = ::flixel::animation::FlxAnimation_obj::__new(hx::ObjectPtr<OBJ_>(this),Name,frameIndices,FrameRate,Looped);		HX_STACK_VAR(anim,"anim");
				HX_STACK_LINE(265)
				this->_animations->set(Name,anim);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(FlxAnimationController_obj,addByStringIndicies,(void))

Void FlxAnimationController_obj::addByIndicies( ::String Name,::String Prefix,Array< int > Indicies,::String Postfix,hx::Null< int >  __o_FrameRate,hx::Null< bool >  __o_Looped){
int FrameRate = __o_FrameRate.Default(30);
bool Looped = __o_Looped.Default(true);
	HX_STACK_FRAME("flixel.animation.FlxAnimationController","addByIndicies",0xb9954552,"flixel.animation.FlxAnimationController.addByIndicies","flixel/animation/FlxAnimationController.hx",281,0xa6f01372)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Name,"Name")
	HX_STACK_ARG(Prefix,"Prefix")
	HX_STACK_ARG(Indicies,"Indicies")
	HX_STACK_ARG(Postfix,"Postfix")
	HX_STACK_ARG(FrameRate,"FrameRate")
	HX_STACK_ARG(Looped,"Looped")
{
		HX_STACK_LINE(281)
		if (((bool((this->_sprite->cachedGraphics != null())) && bool((this->_sprite->cachedGraphics->data != null()))))){
			HX_STACK_LINE(283)
			Array< int > frameIndices = Array_obj< int >::__new();		HX_STACK_VAR(frameIndices,"frameIndices");
			HX_STACK_LINE(284)
			int l = Indicies->length;		HX_STACK_VAR(l,"l");
			HX_STACK_LINE(285)
			{
				HX_STACK_LINE(285)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(285)
				while(((_g < l))){
					HX_STACK_LINE(285)
					int i = (_g)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(287)
					int indexToAdd = this->findSpriteFrame(Prefix,Indicies->__get(i),Postfix);		HX_STACK_VAR(indexToAdd,"indexToAdd");
					HX_STACK_LINE(288)
					if (((indexToAdd != (int)-1))){
						HX_STACK_LINE(290)
						frameIndices->push(indexToAdd);
					}
				}
			}
			HX_STACK_LINE(294)
			if (((frameIndices->length > (int)0))){
				HX_STACK_LINE(296)
				::flixel::animation::FlxAnimation anim = ::flixel::animation::FlxAnimation_obj::__new(hx::ObjectPtr<OBJ_>(this),Name,frameIndices,FrameRate,Looped);		HX_STACK_VAR(anim,"anim");
				HX_STACK_LINE(297)
				this->_animations->set(Name,anim);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(FlxAnimationController_obj,addByIndicies,(void))

int FlxAnimationController_obj::findSpriteFrame( ::String Prefix,int Index,::String Postfix){
	HX_STACK_FRAME("flixel.animation.FlxAnimationController","findSpriteFrame",0x746a2bcb,"flixel.animation.FlxAnimationController.findSpriteFrame","flixel/animation/FlxAnimationController.hx",309,0xa6f01372)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Prefix,"Prefix")
	HX_STACK_ARG(Index,"Index")
	HX_STACK_ARG(Postfix,"Postfix")
	HX_STACK_LINE(310)
	int numFrames = this->_sprite->frames;		HX_STACK_VAR(numFrames,"numFrames");
	HX_STACK_LINE(311)
	Array< ::Dynamic > flxFrames = this->_sprite->framesData->frames;		HX_STACK_VAR(flxFrames,"flxFrames");
	HX_STACK_LINE(312)
	{
		HX_STACK_LINE(312)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(312)
		while(((_g < numFrames))){
			HX_STACK_LINE(312)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(314)
			::String name = flxFrames->__get(i).StaticCast< ::flixel::system::layer::frames::FlxFrame >()->name;		HX_STACK_VAR(name,"name");
			HX_STACK_LINE(315)
			if (((  ((::StringTools_obj::startsWith(name,Prefix))) ? bool(::StringTools_obj::endsWith(name,Postfix)) : bool(false) ))){
				HX_STACK_LINE(317)
				Dynamic index = ::Std_obj::parseInt(name.substring(Prefix.length,(name.length - Postfix.length)));		HX_STACK_VAR(index,"index");
				HX_STACK_LINE(318)
				if (((bool((index != null())) && bool((index == Index))))){
					HX_STACK_LINE(320)
					return i;
				}
			}
		}
	}
	HX_STACK_LINE(325)
	return (int)-1;
}


HX_DEFINE_DYNAMIC_FUNC3(FlxAnimationController_obj,findSpriteFrame,return )

Void FlxAnimationController_obj::addByPrefix( ::String Name,::String Prefix,hx::Null< int >  __o_FrameRate,hx::Null< bool >  __o_Looped){
int FrameRate = __o_FrameRate.Default(30);
bool Looped = __o_Looped.Default(true);
	HX_STACK_FRAME("flixel.animation.FlxAnimationController","addByPrefix",0x4347f9a6,"flixel.animation.FlxAnimationController.addByPrefix","flixel/animation/FlxAnimationController.hx",337,0xa6f01372)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Name,"Name")
	HX_STACK_ARG(Prefix,"Prefix")
	HX_STACK_ARG(FrameRate,"FrameRate")
	HX_STACK_ARG(Looped,"Looped")
{
		HX_STACK_LINE(337)
		if (((bool((this->_sprite->cachedGraphics != null())) && bool((this->_sprite->cachedGraphics->data != null()))))){
			HX_STACK_LINE(339)
			Array< ::Dynamic > animFrames = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(animFrames,"animFrames");
			HX_STACK_LINE(340)
			int l = this->_sprite->framesData->frames->length;		HX_STACK_VAR(l,"l");
			HX_STACK_LINE(341)
			{
				HX_STACK_LINE(341)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(341)
				while(((_g < l))){
					HX_STACK_LINE(341)
					int i = (_g)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(343)
					if ((::StringTools_obj::startsWith(this->_sprite->framesData->frames->__get(i).StaticCast< ::flixel::system::layer::frames::FlxFrame >()->name,Prefix))){
						HX_STACK_LINE(345)
						animFrames->push(this->_sprite->framesData->frames->__get(i).StaticCast< ::flixel::system::layer::frames::FlxFrame >());
					}
				}
			}
			HX_STACK_LINE(349)
			if (((animFrames->length > (int)0))){
				HX_STACK_LINE(351)
				::String name = animFrames->__get((int)0).StaticCast< ::flixel::system::layer::frames::FlxFrame >()->name;		HX_STACK_VAR(name,"name");
				HX_STACK_LINE(352)
				::String postFix = name.substring(name.indexOf(HX_CSTRING("."),Prefix.length),name.length);		HX_STACK_VAR(postFix,"postFix");
				HX_STACK_LINE(353)
				::flixel::animation::FlxAnimationController_obj::prefixLength = Prefix.length;
				HX_STACK_LINE(354)
				::flixel::animation::FlxAnimationController_obj::postfixLength = postFix.length;
				HX_STACK_LINE(355)
				animFrames->sort(::flixel::animation::FlxAnimationController_obj::frameSortFunction_dyn());
				HX_STACK_LINE(356)
				Array< int > frameIndices = Array_obj< int >::__new();		HX_STACK_VAR(frameIndices,"frameIndices");
				HX_STACK_LINE(358)
				l = animFrames->length;
				HX_STACK_LINE(359)
				{
					HX_STACK_LINE(359)
					int _g = (int)0;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(359)
					while(((_g < l))){
						HX_STACK_LINE(359)
						int i = (_g)++;		HX_STACK_VAR(i,"i");
						HX_STACK_LINE(361)
						frameIndices->push(::flixel::util::FlxArrayUtil_obj::indexOf_flixel_system_layer_frames_FlxFrame(this->_sprite->framesData->frames,animFrames->__get(i).StaticCast< ::flixel::system::layer::frames::FlxFrame >(),null()));
					}
				}
				HX_STACK_LINE(364)
				if (((frameIndices->length > (int)0))){
					HX_STACK_LINE(366)
					::flixel::animation::FlxAnimation anim = ::flixel::animation::FlxAnimation_obj::__new(hx::ObjectPtr<OBJ_>(this),Name,frameIndices,FrameRate,Looped);		HX_STACK_VAR(anim,"anim");
					HX_STACK_LINE(367)
					this->_animations->set(Name,anim);
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(FlxAnimationController_obj,addByPrefix,(void))

Void FlxAnimationController_obj::play( ::String AnimName,hx::Null< bool >  __o_Force,hx::Null< int >  __o_Frame){
bool Force = __o_Force.Default(false);
int Frame = __o_Frame.Default(0);
	HX_STACK_FRAME("flixel.animation.FlxAnimationController","play",0xeddc2ed8,"flixel.animation.FlxAnimationController.play","flixel/animation/FlxAnimationController.hx",381,0xa6f01372)
	HX_STACK_THIS(this)
	HX_STACK_ARG(AnimName,"AnimName")
	HX_STACK_ARG(Force,"Force")
	HX_STACK_ARG(Frame,"Frame")
{
		HX_STACK_LINE(382)
		if (((AnimName == null()))){
			HX_STACK_LINE(384)
			if (((this->_curAnim != null()))){
				HX_STACK_LINE(386)
				this->_curAnim->stop();
			}
			HX_STACK_LINE(388)
			this->_curAnim = null();
		}
		HX_STACK_LINE(391)
		if (((  ((!(((AnimName == null()))))) ? bool((this->_animations->get(AnimName) == null())) : bool(true) ))){
			HX_STACK_LINE(393)
			::flixel::FlxG_obj::log->advanced(((HX_CSTRING("No animation called \"") + AnimName) + HX_CSTRING("\"")),::flixel::system::debug::LogStyle_obj::WARNING,true);
			HX_STACK_LINE(394)
			return null();
		}
		HX_STACK_LINE(397)
		if (((bool((this->_curAnim != null())) && bool((AnimName != this->_curAnim->name))))){
			HX_STACK_LINE(399)
			this->_curAnim->stop();
		}
		HX_STACK_LINE(401)
		this->_curAnim = this->_animations->get(AnimName);
		HX_STACK_LINE(402)
		this->_curAnim->play(Force,Frame);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(FlxAnimationController_obj,play,(void))

Void FlxAnimationController_obj::pause( ){
{
		HX_STACK_FRAME("flixel.animation.FlxAnimationController","pause",0x2b969d92,"flixel.animation.FlxAnimationController.pause","flixel/animation/FlxAnimationController.hx",410,0xa6f01372)
		HX_STACK_THIS(this)
		HX_STACK_LINE(410)
		if (((this->_curAnim != null()))){
			HX_STACK_LINE(412)
			this->_curAnim->paused = true;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxAnimationController_obj,pause,(void))

Void FlxAnimationController_obj::resume( ){
{
		HX_STACK_FRAME("flixel.animation.FlxAnimationController","resume",0x11336b91,"flixel.animation.FlxAnimationController.resume","flixel/animation/FlxAnimationController.hx",421,0xa6f01372)
		HX_STACK_THIS(this)
		HX_STACK_LINE(421)
		if (((this->_curAnim != null()))){
			HX_STACK_LINE(423)
			this->_curAnim->paused = false;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxAnimationController_obj,resume,(void))

::flixel::animation::FlxAnimation FlxAnimationController_obj::getByName( ::String Name){
	HX_STACK_FRAME("flixel.animation.FlxAnimationController","getByName",0x1940f994,"flixel.animation.FlxAnimationController.getByName","flixel/animation/FlxAnimationController.hx",432,0xa6f01372)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Name,"Name")
	HX_STACK_LINE(432)
	return this->_animations->get(Name);
}


HX_DEFINE_DYNAMIC_FUNC1(FlxAnimationController_obj,getByName,return )

Void FlxAnimationController_obj::randomFrame( ){
{
		HX_STACK_FRAME("flixel.animation.FlxAnimationController","randomFrame",0x12c43ec6,"flixel.animation.FlxAnimationController.randomFrame","flixel/animation/FlxAnimationController.hx",440,0xa6f01372)
		HX_STACK_THIS(this)
		HX_STACK_LINE(441)
		if (((this->_curAnim != null()))){
			HX_STACK_LINE(443)
			this->_curAnim->stop();
			HX_STACK_LINE(444)
			this->_curAnim = null();
		}
		HX_STACK_LINE(446)
		this->set_frameIndex(::flixel::util::FlxRandom_obj::intRanged((int)0,(this->_sprite->frames - (int)1),null()));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxAnimationController_obj,randomFrame,(void))

int FlxAnimationController_obj::set_frameIndex( int Frame){
	HX_STACK_FRAME("flixel.animation.FlxAnimationController","set_frameIndex",0xd769c646,"flixel.animation.FlxAnimationController.set_frameIndex","flixel/animation/FlxAnimationController.hx",450,0xa6f01372)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Frame,"Frame")
	HX_STACK_LINE(451)
	if (((this->_sprite->framesData != null()))){
		HX_STACK_LINE(453)
		Frame = hx::Mod(Frame,this->_sprite->frames);
		HX_STACK_LINE(454)
		this->_sprite->set_frame(this->_sprite->framesData->frames->__get(Frame).StaticCast< ::flixel::system::layer::frames::FlxFrame >());
		HX_STACK_LINE(456)
		if (((this->callback_dyn() != null()))){
			HX_STACK_LINE(458)
			::String _g;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(458)
			if (((this->_curAnim != null()))){
				HX_STACK_LINE(458)
				_g = this->_curAnim->name;
			}
			else{
				HX_STACK_LINE(458)
				_g = null();
			}
			HX_STACK_LINE(458)
			this->callback(_g,(  (((this->_curAnim != null()))) ? int(this->_curAnim->curFrame) : int(Frame) ),Frame);
		}
	}
	HX_STACK_LINE(462)
	return this->frameIndex = Frame;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxAnimationController_obj,set_frameIndex,return )

::String FlxAnimationController_obj::get_frameName( ){
	HX_STACK_FRAME("flixel.animation.FlxAnimationController","get_frameName",0x1674c78b,"flixel.animation.FlxAnimationController.get_frameName","flixel/animation/FlxAnimationController.hx",467,0xa6f01372)
	HX_STACK_THIS(this)
	HX_STACK_LINE(467)
	return this->_sprite->frame->name;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxAnimationController_obj,get_frameName,return )

::String FlxAnimationController_obj::set_frameName( ::String Value){
	HX_STACK_FRAME("flixel.animation.FlxAnimationController","set_frameName",0x5b7aa997,"flixel.animation.FlxAnimationController.set_frameName","flixel/animation/FlxAnimationController.hx",471,0xa6f01372)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Value,"Value")
	HX_STACK_LINE(472)
	if (((  (((this->_sprite->framesData != null()))) ? bool(this->_sprite->framesData->framesHash->exists(Value)) : bool(false) ))){
		HX_STACK_LINE(474)
		if (((this->_curAnim != null()))){
			HX_STACK_LINE(476)
			this->_curAnim->stop();
			HX_STACK_LINE(477)
			this->_curAnim = null();
		}
		HX_STACK_LINE(480)
		::flixel::system::layer::frames::FlxFrame frame = this->_sprite->framesData->framesHash->get(Value);		HX_STACK_VAR(frame,"frame");
		HX_STACK_LINE(481)
		if (((frame != null()))){
			HX_STACK_LINE(483)
			this->set_frameIndex(::flixel::util::FlxArrayUtil_obj::indexOf_flixel_system_layer_frames_FlxFrame(this->_sprite->framesData->frames,frame,null()));
		}
	}
	HX_STACK_LINE(487)
	return Value;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxAnimationController_obj,set_frameName,return )

::String FlxAnimationController_obj::get_name( ){
	HX_STACK_FRAME("flixel.animation.FlxAnimationController","get_name",0x9c9870b8,"flixel.animation.FlxAnimationController.get_name","flixel/animation/FlxAnimationController.hx",494,0xa6f01372)
	HX_STACK_THIS(this)
	HX_STACK_LINE(495)
	::String animName = null();		HX_STACK_VAR(animName,"animName");
	HX_STACK_LINE(496)
	if (((this->_curAnim != null()))){
		HX_STACK_LINE(498)
		animName = this->_curAnim->name;
	}
	HX_STACK_LINE(500)
	return animName;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxAnimationController_obj,get_name,return )

::String FlxAnimationController_obj::set_name( ::String AnimName){
	HX_STACK_FRAME("flixel.animation.FlxAnimationController","set_name",0x4af5ca2c,"flixel.animation.FlxAnimationController.set_name","flixel/animation/FlxAnimationController.hx",508,0xa6f01372)
	HX_STACK_THIS(this)
	HX_STACK_ARG(AnimName,"AnimName")
	HX_STACK_LINE(509)
	this->play(AnimName,null(),null());
	HX_STACK_LINE(510)
	return AnimName;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxAnimationController_obj,set_name,return )

::flixel::animation::FlxAnimation FlxAnimationController_obj::get_curAnim( ){
	HX_STACK_FRAME("flixel.animation.FlxAnimationController","get_curAnim",0xd32cfb64,"flixel.animation.FlxAnimationController.get_curAnim","flixel/animation/FlxAnimationController.hx",517,0xa6f01372)
	HX_STACK_THIS(this)
	HX_STACK_LINE(518)
	::flixel::animation::FlxAnimation anim = null();		HX_STACK_VAR(anim,"anim");
	HX_STACK_LINE(519)
	if (((bool((bool((this->_curAnim != null())) && bool((this->_curAnim->delay > (int)0)))) && bool(((bool(this->_curAnim->looped) || bool(!(this->_curAnim->finished)))))))){
		HX_STACK_LINE(521)
		anim = this->_curAnim;
	}
	HX_STACK_LINE(523)
	return anim;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxAnimationController_obj,get_curAnim,return )

::flixel::animation::FlxAnimation FlxAnimationController_obj::set_curAnim( ::flixel::animation::FlxAnimation Anim){
	HX_STACK_FRAME("flixel.animation.FlxAnimationController","set_curAnim",0xdd9a0270,"flixel.animation.FlxAnimationController.set_curAnim","flixel/animation/FlxAnimationController.hx",531,0xa6f01372)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Anim,"Anim")
	HX_STACK_LINE(532)
	if (((bool((Anim != null())) && bool((Anim != this->_curAnim))))){
		HX_STACK_LINE(534)
		if (((this->_curAnim != null()))){
			HX_STACK_LINE(536)
			this->_curAnim->stop();
		}
		HX_STACK_LINE(538)
		Anim->play(null(),null());
	}
	HX_STACK_LINE(540)
	return this->_curAnim = Anim;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxAnimationController_obj,set_curAnim,return )

bool FlxAnimationController_obj::get_paused( ){
	HX_STACK_FRAME("flixel.animation.FlxAnimationController","get_paused",0x1a2b745b,"flixel.animation.FlxAnimationController.get_paused","flixel/animation/FlxAnimationController.hx",544,0xa6f01372)
	HX_STACK_THIS(this)
	HX_STACK_LINE(545)
	bool paused = false;		HX_STACK_VAR(paused,"paused");
	HX_STACK_LINE(546)
	if (((this->_curAnim != null()))){
		HX_STACK_LINE(548)
		paused = this->_curAnim->paused;
	}
	HX_STACK_LINE(550)
	return paused;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxAnimationController_obj,get_paused,return )

bool FlxAnimationController_obj::set_paused( bool Value){
	HX_STACK_FRAME("flixel.animation.FlxAnimationController","set_paused",0x1da912cf,"flixel.animation.FlxAnimationController.set_paused","flixel/animation/FlxAnimationController.hx",554,0xa6f01372)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Value,"Value")
	HX_STACK_LINE(555)
	if (((this->_curAnim != null()))){
		HX_STACK_LINE(557)
		this->_curAnim->paused = Value;
	}
	HX_STACK_LINE(559)
	return Value;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxAnimationController_obj,set_paused,return )

bool FlxAnimationController_obj::get_finished( ){
	HX_STACK_FRAME("flixel.animation.FlxAnimationController","get_finished",0x1eabcc5f,"flixel.animation.FlxAnimationController.get_finished","flixel/animation/FlxAnimationController.hx",563,0xa6f01372)
	HX_STACK_THIS(this)
	HX_STACK_LINE(564)
	bool finished = true;		HX_STACK_VAR(finished,"finished");
	HX_STACK_LINE(565)
	if (((this->_curAnim != null()))){
		HX_STACK_LINE(567)
		finished = this->_curAnim->finished;
	}
	HX_STACK_LINE(569)
	return finished;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxAnimationController_obj,get_finished,return )

bool FlxAnimationController_obj::set_finished( bool Value){
	HX_STACK_FRAME("flixel.animation.FlxAnimationController","set_finished",0x33a4efd3,"flixel.animation.FlxAnimationController.set_finished","flixel/animation/FlxAnimationController.hx",573,0xa6f01372)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Value,"Value")
	HX_STACK_LINE(574)
	if (((bool((Value == true)) && bool((this->_curAnim != null()))))){
		HX_STACK_LINE(576)
		this->_curAnim->finished = true;
		HX_STACK_LINE(577)
		this->set_frameIndex((this->_curAnim->_frames->length - (int)1));
	}
	HX_STACK_LINE(579)
	return Value;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxAnimationController_obj,set_finished,return )

int FlxAnimationController_obj::get_frames( ){
	HX_STACK_FRAME("flixel.animation.FlxAnimationController","get_frames",0xd72ce353,"flixel.animation.FlxAnimationController.get_frames","flixel/animation/FlxAnimationController.hx",584,0xa6f01372)
	HX_STACK_THIS(this)
	HX_STACK_LINE(584)
	return this->_sprite->frames;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxAnimationController_obj,get_frames,return )

int FlxAnimationController_obj::getFrameIndex( ::flixel::system::layer::frames::FlxFrame Frame){
	HX_STACK_FRAME("flixel.animation.FlxAnimationController","getFrameIndex",0x1c3dee77,"flixel.animation.FlxAnimationController.getFrameIndex","flixel/animation/FlxAnimationController.hx",594,0xa6f01372)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Frame,"Frame")
	HX_STACK_LINE(594)
	return ::flixel::util::FlxArrayUtil_obj::indexOf_flixel_system_layer_frames_FlxFrame(this->_sprite->framesData->frames,Frame,null());
}


HX_DEFINE_DYNAMIC_FUNC1(FlxAnimationController_obj,getFrameIndex,return )

int FlxAnimationController_obj::prefixLength;

int FlxAnimationController_obj::postfixLength;

int FlxAnimationController_obj::frameSortFunction( ::flixel::system::layer::frames::FlxFrame frame1,::flixel::system::layer::frames::FlxFrame frame2){
	HX_STACK_FRAME("flixel.animation.FlxAnimationController","frameSortFunction",0x485c30ff,"flixel.animation.FlxAnimationController.frameSortFunction","flixel/animation/FlxAnimationController.hx",601,0xa6f01372)
	HX_STACK_ARG(frame1,"frame1")
	HX_STACK_ARG(frame2,"frame2")
	HX_STACK_LINE(602)
	::String name1 = frame1->name;		HX_STACK_VAR(name1,"name1");
	HX_STACK_LINE(603)
	::String name2 = frame2->name;		HX_STACK_VAR(name2,"name2");
	HX_STACK_LINE(605)
	int num1 = ::Std_obj::parseInt(name1.substring(::flixel::animation::FlxAnimationController_obj::prefixLength,(name1.length - ::flixel::animation::FlxAnimationController_obj::postfixLength)));		HX_STACK_VAR(num1,"num1");
	HX_STACK_LINE(606)
	int num2 = ::Std_obj::parseInt(name2.substring(::flixel::animation::FlxAnimationController_obj::prefixLength,(name2.length - ::flixel::animation::FlxAnimationController_obj::postfixLength)));		HX_STACK_VAR(num2,"num2");
	HX_STACK_LINE(608)
	if (((num1 > num2))){
		HX_STACK_LINE(610)
		return (int)1;
	}
	else{
		HX_STACK_LINE(612)
		if (((num2 > num1))){
			HX_STACK_LINE(614)
			return (int)-1;
		}
	}
	HX_STACK_LINE(617)
	return (int)0;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FlxAnimationController_obj,frameSortFunction,return )


FlxAnimationController_obj::FlxAnimationController_obj()
{
}

void FlxAnimationController_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FlxAnimationController);
	HX_MARK_MEMBER_NAME(frameIndex,"frameIndex");
	HX_MARK_MEMBER_NAME(frames,"frames");
	HX_MARK_MEMBER_NAME(callback,"callback");
	HX_MARK_MEMBER_NAME(_sprite,"_sprite");
	HX_MARK_MEMBER_NAME(_curAnim,"_curAnim");
	HX_MARK_MEMBER_NAME(_animations,"_animations");
	HX_MARK_MEMBER_NAME(_prerotated,"_prerotated");
	HX_MARK_END_CLASS();
}

void FlxAnimationController_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(frameIndex,"frameIndex");
	HX_VISIT_MEMBER_NAME(frames,"frames");
	HX_VISIT_MEMBER_NAME(callback,"callback");
	HX_VISIT_MEMBER_NAME(_sprite,"_sprite");
	HX_VISIT_MEMBER_NAME(_curAnim,"_curAnim");
	HX_VISIT_MEMBER_NAME(_animations,"_animations");
	HX_VISIT_MEMBER_NAME(_prerotated,"_prerotated");
}

Dynamic FlxAnimationController_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"get") ) { return get_dyn(); }
		if (HX_FIELD_EQ(inName,"add") ) { return add_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return get_name(); }
		if (HX_FIELD_EQ(inName,"play") ) { return play_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"pause") ) { return pause_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"paused") ) { return get_paused(); }
		if (HX_FIELD_EQ(inName,"frames") ) { return inCallProp ? get_frames() : frames; }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"resume") ) { return resume_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"curAnim") ) { return get_curAnim(); }
		if (HX_FIELD_EQ(inName,"_sprite") ) { return _sprite; }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"finished") ) { return get_finished(); }
		if (HX_FIELD_EQ(inName,"callback") ) { return callback; }
		if (HX_FIELD_EQ(inName,"_curAnim") ) { return _curAnim; }
		if (HX_FIELD_EQ(inName,"copyFrom") ) { return copyFrom_dyn(); }
		if (HX_FIELD_EQ(inName,"get_name") ) { return get_name_dyn(); }
		if (HX_FIELD_EQ(inName,"set_name") ) { return set_name_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"frameName") ) { return get_frameName(); }
		if (HX_FIELD_EQ(inName,"getByName") ) { return getByName_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"frameIndex") ) { return frameIndex; }
		if (HX_FIELD_EQ(inName,"addByNames") ) { return addByNames_dyn(); }
		if (HX_FIELD_EQ(inName,"get_paused") ) { return get_paused_dyn(); }
		if (HX_FIELD_EQ(inName,"set_paused") ) { return set_paused_dyn(); }
		if (HX_FIELD_EQ(inName,"get_frames") ) { return get_frames_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_animations") ) { return _animations; }
		if (HX_FIELD_EQ(inName,"_prerotated") ) { return _prerotated; }
		if (HX_FIELD_EQ(inName,"addByPrefix") ) { return addByPrefix_dyn(); }
		if (HX_FIELD_EQ(inName,"randomFrame") ) { return randomFrame_dyn(); }
		if (HX_FIELD_EQ(inName,"get_curAnim") ) { return get_curAnim_dyn(); }
		if (HX_FIELD_EQ(inName,"set_curAnim") ) { return set_curAnim_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"prefixLength") ) { return prefixLength; }
		if (HX_FIELD_EQ(inName,"get_finished") ) { return get_finished_dyn(); }
		if (HX_FIELD_EQ(inName,"set_finished") ) { return set_finished_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"postfixLength") ) { return postfixLength; }
		if (HX_FIELD_EQ(inName,"addByIndicies") ) { return addByIndicies_dyn(); }
		if (HX_FIELD_EQ(inName,"get_frameName") ) { return get_frameName_dyn(); }
		if (HX_FIELD_EQ(inName,"set_frameName") ) { return set_frameName_dyn(); }
		if (HX_FIELD_EQ(inName,"getFrameIndex") ) { return getFrameIndex_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"set_frameIndex") ) { return set_frameIndex_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"clearPrerotated") ) { return clearPrerotated_dyn(); }
		if (HX_FIELD_EQ(inName,"clearAnimations") ) { return clearAnimations_dyn(); }
		if (HX_FIELD_EQ(inName,"findSpriteFrame") ) { return findSpriteFrame_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"createPrerotated") ) { return createPrerotated_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"frameSortFunction") ) { return frameSortFunction_dyn(); }
		if (HX_FIELD_EQ(inName,"destroyAnimations") ) { return destroyAnimations_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"addByStringIndicies") ) { return addByStringIndicies_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxAnimationController_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return set_name(inValue); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"paused") ) { return set_paused(inValue); }
		if (HX_FIELD_EQ(inName,"frames") ) { frames=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"curAnim") ) { return set_curAnim(inValue); }
		if (HX_FIELD_EQ(inName,"_sprite") ) { _sprite=inValue.Cast< ::flixel::FlxSprite >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"finished") ) { return set_finished(inValue); }
		if (HX_FIELD_EQ(inName,"callback") ) { callback=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_curAnim") ) { _curAnim=inValue.Cast< ::flixel::animation::FlxAnimation >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"frameName") ) { return set_frameName(inValue); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"frameIndex") ) { if (inCallProp) return set_frameIndex(inValue);frameIndex=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_animations") ) { _animations=inValue.Cast< ::haxe::ds::StringMap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_prerotated") ) { _prerotated=inValue.Cast< ::flixel::animation::FlxPrerotatedAnimation >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"prefixLength") ) { prefixLength=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"postfixLength") ) { postfixLength=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxAnimationController_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("curAnim"));
	outFields->push(HX_CSTRING("frameIndex"));
	outFields->push(HX_CSTRING("frameName"));
	outFields->push(HX_CSTRING("name"));
	outFields->push(HX_CSTRING("paused"));
	outFields->push(HX_CSTRING("finished"));
	outFields->push(HX_CSTRING("frames"));
	outFields->push(HX_CSTRING("_sprite"));
	outFields->push(HX_CSTRING("_curAnim"));
	outFields->push(HX_CSTRING("_animations"));
	outFields->push(HX_CSTRING("_prerotated"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("prefixLength"),
	HX_CSTRING("postfixLength"),
	HX_CSTRING("frameSortFunction"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(FlxAnimationController_obj,frameIndex),HX_CSTRING("frameIndex")},
	{hx::fsInt,(int)offsetof(FlxAnimationController_obj,frames),HX_CSTRING("frames")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(FlxAnimationController_obj,callback),HX_CSTRING("callback")},
	{hx::fsObject /*::flixel::FlxSprite*/ ,(int)offsetof(FlxAnimationController_obj,_sprite),HX_CSTRING("_sprite")},
	{hx::fsObject /*::flixel::animation::FlxAnimation*/ ,(int)offsetof(FlxAnimationController_obj,_curAnim),HX_CSTRING("_curAnim")},
	{hx::fsObject /*::haxe::ds::StringMap*/ ,(int)offsetof(FlxAnimationController_obj,_animations),HX_CSTRING("_animations")},
	{hx::fsObject /*::flixel::animation::FlxPrerotatedAnimation*/ ,(int)offsetof(FlxAnimationController_obj,_prerotated),HX_CSTRING("_prerotated")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("frameIndex"),
	HX_CSTRING("frames"),
	HX_CSTRING("callback"),
	HX_CSTRING("_sprite"),
	HX_CSTRING("_curAnim"),
	HX_CSTRING("_animations"),
	HX_CSTRING("_prerotated"),
	HX_CSTRING("update"),
	HX_CSTRING("copyFrom"),
	HX_CSTRING("createPrerotated"),
	HX_CSTRING("destroyAnimations"),
	HX_CSTRING("destroy"),
	HX_CSTRING("clearPrerotated"),
	HX_CSTRING("clearAnimations"),
	HX_CSTRING("get"),
	HX_CSTRING("add"),
	HX_CSTRING("addByNames"),
	HX_CSTRING("addByStringIndicies"),
	HX_CSTRING("addByIndicies"),
	HX_CSTRING("findSpriteFrame"),
	HX_CSTRING("addByPrefix"),
	HX_CSTRING("play"),
	HX_CSTRING("pause"),
	HX_CSTRING("resume"),
	HX_CSTRING("getByName"),
	HX_CSTRING("randomFrame"),
	HX_CSTRING("set_frameIndex"),
	HX_CSTRING("get_frameName"),
	HX_CSTRING("set_frameName"),
	HX_CSTRING("get_name"),
	HX_CSTRING("set_name"),
	HX_CSTRING("get_curAnim"),
	HX_CSTRING("set_curAnim"),
	HX_CSTRING("get_paused"),
	HX_CSTRING("set_paused"),
	HX_CSTRING("get_finished"),
	HX_CSTRING("set_finished"),
	HX_CSTRING("get_frames"),
	HX_CSTRING("getFrameIndex"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxAnimationController_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(FlxAnimationController_obj::prefixLength,"prefixLength");
	HX_MARK_MEMBER_NAME(FlxAnimationController_obj::postfixLength,"postfixLength");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxAnimationController_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(FlxAnimationController_obj::prefixLength,"prefixLength");
	HX_VISIT_MEMBER_NAME(FlxAnimationController_obj::postfixLength,"postfixLength");
};

#endif

Class FlxAnimationController_obj::__mClass;

void FlxAnimationController_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.animation.FlxAnimationController"), hx::TCanCast< FlxAnimationController_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , sMemberStorageInfo
#endif
);
}

void FlxAnimationController_obj::__boot()
{
	prefixLength= (int)0;
	postfixLength= (int)0;
}

} // end namespace flixel
} // end namespace animation
