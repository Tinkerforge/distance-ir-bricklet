program ExampleThreshold;

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
    procedure ReachedCB(const distance: word);
    procedure Execute;
  end;

const
  HOST = 'localhost';
  PORT = 4223;
  UID = '6Vw'; { Change to your UID }

var
  e: TExample;

{ Callback for distance smaller than 20 cm }
procedure TExample.ReachedCB(const distance: word);
begin
  WriteLn(Format('Distance is smaller than 20 cm: %f cm', [distance/10.0]));
end;

procedure TExample.Execute;
begin
  { Create IP connection to brickd }
  ipcon := TIPConnection.Create(HOST, PORT);

  { Create device object }
  dr := TBrickletDistanceIR.Create(UID);

  { Add device to IP connection }
  ipcon.AddDevice(dr);
  { Don't use device before it is added to a connection }

  { Get threshold callbacks with a debounce time of 1 second (1000ms) }
  dr.SetDebouncePeriod(1000);

  { Register threshold reached callback to procedure ReachedCB }
  dr.OnDistanceReached := {$ifdef FPC}@{$endif}ReachedCB;

  { Configure threshold for "smaller than 20cm" (unit is mm) }
  dr.SetDistanceCallbackThreshold('<', 20*10, 0);

  WriteLn('Press key to exit');
  ReadLn;
  ipcon.Destroy;
end;

begin
  e := TExample.Create;
  e.Execute;
  e.Destroy;
end.
