program ExampleSimple;

{$ifdef MSWINDOWS}{$apptype CONSOLE}{$endif}
{$ifdef FPC}{$mode OBJFPC}{$H+}{$endif}

uses
  SysUtils, IPConnection, BrickletDistanceIR;

type
  TExample = class
  private
    ipcon: TIPConnection;
    dr: TBrickletDistanceIR;
  public
    procedure Execute;
  end;

const
  HOST = 'localhost';
  PORT = 4223;
  UID = '6Vw'; { Change to your UID }

var
  e: TExample;

procedure TExample.Execute;
var distance: word;
begin
  { Create IP connection to brickd }
  ipcon := TIPConnection.Create(HOST, PORT);

  { Create device object }
  dr := TBrickletDistanceIR.Create(UID);

  { Add device to IP connection }
  ipcon.AddDevice(dr);
  { Don't use device before it is added to a connection }

  { Get current distance (unit is mm) }
  distance := dr.GetDistance;
  WriteLn(Format('Distance: %f cm', [distance/10.0]));

  WriteLn('Press key to exit');
  ReadLn;
  ipcon.Destroy;
end;

begin
  e := TExample.Create;
  e.Execute;
  e.Destroy;
end.
