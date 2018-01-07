library pascalunit;
{$MODE OBJFPC}

uses
  ctypes;
  
type
  IPlugin = interface
    procedure _release (); cdecl;
    procedure print (); cdecl;
  end;
  TPlugin = class (TInterfacedObject, IPlugin)
  public
    procedure _release (); cdecl;
    procedure print (); cdecl;
    constructor Create ();
    destructor Free ();
  end;
  PPlugin = ^TPlugin;

procedure TPlugin._release (); cdecl; 
begin
  Free;
end;

procedure TPlugin.print (); cdecl; 
begin
  writeln ('Hello World');
end;

procedure _release (this: PPlugin); cdecl;
begin
  this^._release ();
end;

procedure print (this: PPlugin); cdecl; 
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

function  getNewPlugin (): PPlugin; cdecl;
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
