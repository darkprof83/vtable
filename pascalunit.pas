library pascalunit;
{$MODE OBJFPC}
{$include ApiEntry.inc}

uses
  ctypes;
  
type
  IPlugin = interface
    procedure _release (); APIENTRY;
    procedure print (); APIENTRY;
  end;
  TPlugin = class (TInterfacedObject, IPlugin)
  public
    procedure _release (); APIENTRY;
    procedure print (); APIENTRY;
    constructor Create ();
    destructor Free ();
  end;
  PPlugin = ^TPlugin;

procedure TPlugin._release (); APIENTRY; 
begin
  Free;
end;

procedure TPlugin.print (); APIENTRY; 
begin
  writeln ('Hello World');
end;

procedure _release (this: PPlugin); APIENTRY;
begin
  this^._release ();
end;

procedure print (this: PPlugin); APIENTRY; 
begin
  this^.print ();
end;

constructor TPlugin.Create ();
begin
  inherited;
  writeln ('TPlugin.Create');
end;

destructor TPlugin.Free ();
begin
  writeln ('TPlugin.Free');
end;

function  getNewPlugin (): PPlugin; APIENTRY;
var
  plugin: PPlugin;
begin
  New (plugin);
  plugin^ := TPlugin.Create ();
  result := plugin;
end;

exports
  getNewPlugin name 'IPlugin_getNewPlugin', print name 'IPlugin_print', _release name 'IPlugin_release';

begin
end.
